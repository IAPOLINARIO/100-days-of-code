package main

import (
	"fmt"
)

func main() {

	input := []int{1, 6, 5, 2, 4, 3}
	fmt.Println(rotateArray(input))
}

func rotateArray(larryArray []int) (result bool) {
	inversions := 0

	for i := 0; i < len(larryArray); i++ {
		for j := i + 1; j < len(larryArray); j++ {
			if larryArray[i] > larryArray[j] {
				inversions++
			}
		}
	}

	if inversions%2 == 0 {
		result = true
	} else {
		result = false
	}
	return
}
