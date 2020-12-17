package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const (
	endingWord = "aca"
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the word to encrypt:")

	input, _ := reader.ReadString('\n')

	fmt.Printf("Encrypted word: %v \n", Encrypt(strings.TrimSpace(input)))
}

func Encrypt(input string) (result string) {

	m := map[string]string{
		"a": "0",
		"e": "1",
		"i": "2",
		"o": "2",
		"u": "3",
	}

	for i := len(input) - 1; i >= 0; i-- {
		char := string(input[i])
		encryptedChar := m[string(input[i])]

		if encryptedChar != "" {
			result += encryptedChar
		} else {
			result += char
		}

	}
	return result + endingWord
}
