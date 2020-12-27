package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Print(playTheGame(5000000))
}

func playTheGame(input int) string {

	var sb strings.Builder

	for i := input; i >= 1; i-- {
		if input > 1 {
			if input%3 == 0 {
				sb.WriteString(fmt.Sprintf("%d %d\n", input, 0))
				input = input / 3
			} else {
				if (input+1)%3 == 0 {
					sb.WriteString(fmt.Sprintf("%d %v\n", input, "1"))
					input = (input + 1) / 3
				} else {
					sb.WriteString(fmt.Sprintf("%d %v\n", input, "-1"))
					input = (input - 1) / 3
				}
			}
		} else if input == 1 {
			sb.WriteString(fmt.Sprintf("%d", input))
			input = 0
		} else {
			break
		}
	}

	return sb.String()
}
