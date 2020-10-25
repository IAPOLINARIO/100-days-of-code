package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter your age: ")

	input, _ := reader.ReadString('\n')

	age, err := strconv.ParseInt(input, 10, 64)

	if err != nil {
		fmt.Println("Something went wrong")
	} else {
		fmt.Printf("You are %d years old \n", age)
	}

}
