package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Enter the socks configuration:")

	input, err := reader.ReadString('\n')

	if err != nil {
		fmt.Println("Something went wrong with the input...")
	} else {

		result, err := sockPairs(input)

		if err != nil {
			fmt.Println(err)
		} else {
			fmt.Printf("Pair(s) of Sock(s): %v", result)
		}
	}

}

func sockPairs(input string) (result int, err error) {

	socks := make(map[string]int)

	for _, v := range strings.TrimSpace(input) {
		socks[string(v)] = socks[string(v)] + 1

		if socks[string(v)]%2 == 0 {
			result += 1
		}

	}

	return result, err
}
