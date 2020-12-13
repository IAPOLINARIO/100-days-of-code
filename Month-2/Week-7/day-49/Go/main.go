package main

import "fmt"

func main() {
	input := [][]int{
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0, 0},
		{0, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}}

	fmt.Println(isLegitimate(input))
}

func isLegitimate(swimmingPoolBP [][]int) bool {
	for i := 0; i < len(swimmingPoolBP); i++ {
		for j := 0; j < len(swimmingPoolBP[i]); j++ {
			if swimmingPoolBP[i][j] == 1 {
				if i == 0 || j == 0 || i == (len(swimmingPoolBP)-1) || j == (len(swimmingPoolBP[i])-1) {
					return false
				}
			}
		}
	}

	return true
}
