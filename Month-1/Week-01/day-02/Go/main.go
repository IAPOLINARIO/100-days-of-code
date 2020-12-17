package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const (
	Keyword      = "Nemo"
	NotFoundText = "I can't find Nemo :("
	FoundText    = "I found Nemo at %v!\n"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Type the Nemo sentence:")

	input, err := reader.ReadString('\n')

	fmt.Println("........Looking for Nemo..........")

	if err != nil {
		fmt.Printf("Something went wrong: %v\n", err)
	} else {
		nemoPosition := findNemo(input)

		if nemoPosition > 0 {
			fmt.Printf(FoundText, nemoPosition)
		} else {
			fmt.Printf(NotFoundText)
		}
	}

}

func findNemo(input string) int {
	for i, word := range strings.Fields(input) {

		if word == Keyword {
			return i + 1
		}
	}
	return 0
}
