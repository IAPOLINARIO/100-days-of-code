package main

import (
	"fmt"
	"strings"
)

const (
	messageSafe  = "Safe watching!"
	messageAvoid = "NO!"
)

func main() {
	wordsToAvoid := []string{"anime", "meme", "vines", "roasts", "Danny DeVito"}
	input := "vines that butter my eggroll"
	fmt.Println(preventDistractions(input, wordsToAvoid))
}

func preventDistractions(validatePhrase string, wordsToAvoid []string) string {

	for _, word := range strings.Split(validatePhrase, " ") {

		for i := 0; i < len(wordsToAvoid); i++ {
			if wordsToAvoid[i] == word {
				return messageAvoid
			}
		}
	}

	return messageSafe
}
