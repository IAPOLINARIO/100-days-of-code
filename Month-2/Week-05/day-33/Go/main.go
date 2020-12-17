package main

import (
	"fmt"
	"strings"
)

const (
	keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"
)

func main() {
	fmt.Println(keyboardMistakeFix("O S, GOMR YPFSU/"))
}

func keyboardMistakeFix(text string) (result string) {
	for i := 0; i < len(text); i++ {

		if text[i] == ' ' {
			result += string(text[i])
		} else {
			indexOf := strings.Index(keyboard, string(text[i]))
			result += string(keyboard[indexOf-1])
		}
	}

	return
}
