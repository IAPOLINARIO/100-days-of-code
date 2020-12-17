package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	daysInYear = 365
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter your age: ")

	input, _ := reader.ReadString('\n')

	ageResult, err := CalculateAge(input)

	if err != nil {
		fmt.Printf("Sorry, but something went wrong: %v", err)
	} else {
		fmt.Printf("You are %d days old \n", ageResult)
	}

}

func CalculateAge(input string) (int64, error) {

	trimmedInput := strings.TrimRight(input, "\r\n")
	parsedAge, err := strconv.ParseInt(trimmedInput, 10, 64)
	if err != nil {
		return parsedAge, err
	}

	ageinDays := parsedAge * daysInYear

	return ageinDays, err
}
