package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the ip:")

	input, _ := reader.ReadString('\n')
	result := restoreIpAddresses(strings.TrimSpace(input))

	fmt.Println(strings.Join(result, ","))
}

func restoreIpAddresses(input string) (result []string) {
	if len(input) < 4 || len(input) > 12 {
		return nil
	}

	track := make([]string, 0)
	backtrack(input, track, 1, &result)

	return result
}

func backtrack(input string, track []string, key int, result *[]string) {

	if key == 5 {
		if len(input) == 0 {
			str := strings.Join(track, ".")
			*result = append(*result, str)
		}
		return
	}

	for j := 1; j <= 3; j++ {
		if j <= len(input) {
			v, err := strconv.Atoi(input[:j])

			if err == nil && v <= 255 {
				track = append(track, input[:j])
				str := input[j:]

				backtrack(str, track, key+1, result)

				track = track[:len(track)-1]
			}
			if v == 0 {
				break
			}
		}
	}

}
