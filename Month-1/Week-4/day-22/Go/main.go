package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const (
	oficialFootballFieldSize = 7.140 //m2
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Printf("Enter the deforested area (in m2): ")

	input, _ := reader.ReadString('\n')
	deforesteArea, _ := strconv.ParseFloat(strings.TrimSpace(input), 64)

	fmt.Printf("Football fields deforested: %v \n", calcDeforestation(deforesteArea))
}

func calcDeforestation(deforestationArea float64) float64 {
	return math.Round(deforestationArea / oficialFootballFieldSize)
}
