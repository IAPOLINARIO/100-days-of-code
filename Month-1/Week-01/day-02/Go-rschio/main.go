package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strings"
)

func findNemo(s string) int {
	const pattern = "Nemo"
	words := strings.Fields(s)
	for i, w := range words {
		if w == pattern {
			return i + 1
		}
	}
	return -1
}

func FindNemo(s string) string {
	pos := findNemo(s)
	if pos == -1 {
		return "I can't find Nemo :("
	}
	return fmt.Sprintf("I found Nemo at %d!", pos)
}

func main() {
	data, err := ioutil.ReadAll(os.Stdin)
	if err != nil {
		log.Fatalf("failed to read input: %v", err)
	}
	fmt.Println(FindNemo(string(data)))
}
