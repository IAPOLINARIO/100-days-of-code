package main

import (
	"encoding/hex"
	"fmt"
	"strings"
)

func main() {

	input := "hello world"
	fmt.Println(strings.Join(toHex(input), " "))

}

func toHex(word string) (result []string) {

	for _, v := range word {
		result = append(result, hex.EncodeToString([]byte(string(v))))
	}

	return
}
