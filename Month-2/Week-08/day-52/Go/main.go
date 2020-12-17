package main

import "fmt"

func main() {

	input := [][]string{
		{"-", "#", "#", "-"},
		{"-", "-", "#", "-"},
		{"-", "-", "-", "#"},
		{"-", "-", "-", "-"}}

	fmt.Println(*switchGravityOn(input))

}

func switchGravityOn(inputArray [][]string) *[][]string {
	rowsCount := len(inputArray)
	columnsCount := len(inputArray[0])
	var currentBlock string
	var latestBlockIndex int

	for c := 0; c < columnsCount; c++ {
		latestBlockIndex = rowsCount - 1
		for r := rowsCount - 1; r >= 0; r-- {
			currentBlock = inputArray[r][c]
			if currentBlock == "#" {
				inputArray[latestBlockIndex][c] = "#"
				inputArray[r][c] = "-"
				latestBlockIndex--
			}
		}
	}

	return &inputArray

}
