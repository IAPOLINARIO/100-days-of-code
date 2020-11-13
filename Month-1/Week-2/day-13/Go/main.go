package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {

	//reader := bufio.NewReader(os.Stdin)
	//fmt.Println("Enter weights and bags:")

	//input, _ := reader.ReadString('\n')

	//inputNumbers := convertToIntArray(strings.Split(input, ","))

	inputNumbers := []int{4, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}
	fmt.Printf("Can fit: %v \n", CanFit(inputNumbers, 6))
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
		fmt.Printf("Peso do item atual: %v kg\n", v)
		if currentLoad >= maximumLoadPerBag {
			fmt.Printf("Carga atual na saculinha: %v kg\n", currentLoad)
			leftOver += (currentLoad - maximumLoadPerBag)
			fmt.Printf("Sobrou %v kg pra proxima sacola \n", leftOver)
			requiredBags++
			currentLoad = 0
		} else {
			fmt.Printf("Vamo esperar pelo proximo item que cabe mais nessa sacola\n")
		}
	}

	if leftOver%maximumLoadPerBag > 0 {
		extraBags := int(math.Ceil(float64(leftOver) / float64(maximumLoadPerBag)))
		fmt.Printf("Sobrou umas paradas ainda, vamo precisar de mais %v sacolas extras \n", extraBags)
		requiredBags += extraBags
	}
	fmt.Printf("No final vamo precisar de %v sacolas \n", requiredBags)

	return requiredBags <= bags
}
