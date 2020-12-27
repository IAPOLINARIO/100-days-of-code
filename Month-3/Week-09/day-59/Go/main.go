package main

import (
	"fmt"
	"strings"
)

func main() {

	input := "xxxyyyzzz"

	fmt.Print(balanced_bonus(input))

}

func balanced_bonus(sequence string) bool {

	if sequence != "" {
		firstChar := string(sequence[0])
		combinationCount := strings.Count(sequence, firstChar)

		for i := 1; i < len(sequence); i++ {
			if string(sequence[i]) != firstChar {
				if strings.Count(sequence, string(sequence[i])) != combinationCount {
					return false
				}
			}
		}
	}

	return true
}
