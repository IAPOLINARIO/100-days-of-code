package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter weights and bags:")

	input, _ := reader.ReadString('\n')

	inputNumbers := convertToIntArray(strings.Split(input, ","))

	fmt.Printf("Can fit: %v \n", CanFit(inputNumbers, 4))
}

func convertToIntArray(input []string) []int {
	var t2 = []int{}

	for _, i := range input {
		j, err := strconv.Atoi(i)
		if err != nil {
			panic(err)
		}
		t2 = append(t2, j)
	}

	return t2
}

func CanFit(items []int, bags int) bool {
	maximumLoadPerBag := 10
	requiredBags := 0
	leftOver := 0
	currentLoad := 0

	for _, v := range items {
		currentLoad += v
		if currentLoad >= maximumLoadPerBag {
			leftOver += (currentLoad - maximumLoadPerBag)
			requiredBags++
			currentLoad = 0
		}
	}

	if leftOver%maximumLoadPerBag > 0 {
		extraBags := int(math.Ceil(float64(leftOver) / float64(maximumLoadPerBag)))
		requiredBags += extraBags
	}

	return requiredBags <= bags
}
