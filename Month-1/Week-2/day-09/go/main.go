package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Enter the water map:")

	waterMap, _ := reader.ReadString('\n')

	formatedWaterMap := strings.ReplaceAll(strings.ReplaceAll(waterMap, "[", ""), "]", "")
	input := strings.Split(strings.TrimSpace(formatedWaterMap), ",")

	result := buildElevationMap(input)
	fmt.Printf("Water trapped: %v \n", result)
}

func buildElevationMap(input []string) int {
	elevation := 0

	for i := 0; i < len(input); i++ {
		currentValue, _ := strconv.Atoi(input[i])
		if currentValue > 0 {
			currentElevation := 0
			for j := i + 1; j < len(input); j++ {
				nextValue, _ := strconv.Atoi(input[j])
				if nextValue < currentValue {
					if currentValue-nextValue > 1 {
						currentElevation += (currentValue - nextValue)
					} else {
						currentElevation += 1
					}
				} else if nextValue >= currentValue {
					elevation += currentElevation
					i = j - 1
					break
				}

			}
		}

	}

	return elevation
}
