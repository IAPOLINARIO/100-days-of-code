package main

import (
	"fmt"
	"strings"
)

func main() {

	input := []string{"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}

	fmt.Println(identicalFilter(input))
}

func identicalFilter(input []string) (result []string) {

	for _, word := range input {
		if len(word) == 1 {
			result = append(result, word)
		} else {
			for _, char := range word {
				if strings.Count(word, string(char)) == len(word) {
					result = append(result, word)
					break
				}
			}
		}
	}

	return
}
