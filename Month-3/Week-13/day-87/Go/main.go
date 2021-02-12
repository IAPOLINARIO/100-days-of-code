package main

import (
	"fmt"
)

func main() {
	fmt.Print(hulkHelper(4))
}

func hulkHelper(input int) (result string) {
	keyWord := "hate"
	for i := 0; i < input; i++ {
		if i%2 == 0 {
			keyWord = "hate"

		} else {
			keyWord = "love"
		}

		result += fmt.Sprintf("I %v it ", keyWord)
	}

	return result
}
