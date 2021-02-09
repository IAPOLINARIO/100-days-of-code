package main

import (
	"fmt"
)

func main() {
	//This is the start, we get how many cases we will have
	var cases int
	fmt.Scanf("%d", &cases)
	//This is the start of the loop of the many cases we can have
	for x := 0; x < cases; x++ {
		//We get the size, reminder that the array is nXn, a square matrix
		var size int
		fmt.Scanf("%d", &size)

		//We declare the matrix sizeXsize and fill it with zeroes with make(Type,Size)
		matrix := make([][]int, size)
		for i := range matrix {
			matrix[i] = make([]int, size)
		}

		//We fill the matrix with our desired values, row by row.
		for i := 0; i < size; i++ {
			for j := 0; j < size; j++ {
				fmt.Scanf("%d", &matrix[i][j])
			}
		}

		//We get the Vestigium, the sum of the left to right diagonal
		vestigium := 0
		for i := 0; i < size; i++ {
			vestigium += matrix[i][i]
		}

		//This is the code to find repeated numbers in ROWS
		repeatedRows := 0
		for i := 0; i < size; i++ {
			occured := map[int]bool{}
			for j := 0; j < size; j++ {
				if occured[matrix[i][j]] == false {
					occured[matrix[i][j]] = true
				} else {
					repeatedRows += 1
					break
				}
			}

		}

		//This is the code to find repeated numbers in COLLUMNS
		repeatedCollumns := 0
		for i := 0; i < size; i++ {
			occured := map[int]bool{}
			for j := 0; j < size; j++ {
				if occured[matrix[j][i]] == false {
					occured[matrix[j][i]] = true
				} else {
					repeatedCollumns += 1
					break
				}
			}

		}
		//Now we just print our results with the format
		fmt.Printf("\nCase #%d: %d %d %d\n", x+1, vestigium, repeatedRows, repeatedCollumns)
	}
}
