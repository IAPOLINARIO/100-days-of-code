package main

import (
	"fmt"
	"strings"
)

const (
	vowels = "AEIOU"
)

func main() {
	input := "i am healthy"

	result := sigilize(input)

	fmt.Println(result)
}

func sigilize(word string) (result string) {
	for _, char := range word {
		upperChar := strings.ToUpper(string(char))
		if !strings.Contains(vowels, upperChar) && upperChar != " " {
			if strings.Contains(result, upperChar) {
				result = strings.ReplaceAll(result, upperChar, "")
			}
			result += upperChar
		}
	}
	return
}
