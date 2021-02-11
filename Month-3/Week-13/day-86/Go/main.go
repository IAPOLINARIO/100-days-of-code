package main

import "fmt"

func main() {

	input := "internationalization"

	fmt.Print(wordAbbr(input))
}

func wordAbbr(word string) string {
	return fmt.Sprintf("%v%v%v", string(word[0]), len(word)-2, string(word[len(word)-1]))
}
