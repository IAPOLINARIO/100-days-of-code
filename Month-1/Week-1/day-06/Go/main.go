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

	fmt.Println("Input the number:")

	input, err := reader.ReadString('\n')

	if err != nil {
		fmt.Printf("Something went wrong: %v \n", err)
	} else {
		primeInput, _ := strconv.Atoi(strings.TrimSpace(input))
		result, _ := NextPrime(primeInput)

		fmt.Printf("The next prime number is: %v", result)
	}
}

func NextPrime(input int) (result int, err error) {

	if input <= 2 {
		return 2, err
	} else {
		for i := 2; i <= input; i++ {
			if input%i == 0 && i != input {
				return NextPrime(input + 1)
			} else {
				if i == input {
					return input, err
				}
			}
		}
	}

	return result, err
}
