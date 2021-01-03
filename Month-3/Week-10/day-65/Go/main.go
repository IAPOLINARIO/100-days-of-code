package main

import (
	"fmt"
	"regexp"
	"strconv"
	"strings"
)

func main() {

	isbn := "1-56881111-X"

	fmt.Println(validateISBN(isbn))
}

func validateISBN(input string) bool {

	multiplier := 10
	re := regexp.MustCompile("[0-9]+")
	digits := strings.Join(re.FindAllString(input, -1), "")
	lastChar := -1

	fmt.Printf("Input after regex: %v\n", digits)
	if strings.LastIndex(input, "X") == len(input)-1 {
		lastChar = 10
	}

	if len(digits) == multiplier && lastChar == -1 || len(digits) == (multiplier-1) && lastChar == 10 {
		fmt.Printf("Valid input size: %d \n", len(digits))
		totalSum := 0
		for _, d := range digits {
			currentDigit, _ := strconv.Atoi(string(d))
			totalSum += currentDigit * multiplier
			multiplier--
		}

		if lastChar > -1 {
			totalSum += lastChar * multiplier
			multiplier--
		}

		fmt.Printf("Total Sum: %d\n", totalSum)
		return totalSum%11 == 0

	}

	fmt.Println("Invalid input size")
	return false

}
