package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const ()

func main() {

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the digits:")

	input, err := reader.ReadString('\n')

	if err != nil {
		_ = fmt.Errorf("Error: %v", err)
	}

	arr := letterCombinations(strings.TrimSpace(input))

	fmt.Println(arr)
}

func letterCombinations(digits string) []string {
	table := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	ret := []string{}
	if len(digits) > 0 {
		help(&ret, digits, "", 0, table)
	}
	return ret
}

func help(ret *[]string, digits string, cur string, index int, table []string) {
	if index == len(digits) {
		*ret = append(*ret, cur)
		return
	}
	tmp := table[digits[index]-48]

	for _, t := range tmp {
		help(ret, digits, cur+string(t), index+1, table)
	}
}
