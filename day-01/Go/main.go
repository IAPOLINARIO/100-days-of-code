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

	fmt.Print("Enter your age: ")

	input, _ := reader.ReadString('\n')

	age, err := strconv.ParseInt(strings.TrimRight(input, "\r\n"), 10, 64)

	if err != nil {
		fmt.Println("Something went wrong")
	} else {
		fmt.Printf("You are %d years old \n", age)
	}

}
