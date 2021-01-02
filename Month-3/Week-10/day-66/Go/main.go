package main

import (
	"fmt"
	"math/rand"
	"regexp"
	"strconv"
	"strings"
	"time"
)

func main() {
	fmt.Println(generateISBN())
}

func generateISBN() string {

	var sb strings.Builder

	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)

	sum := 0

	for i := 0; i < 9; i++ {
		number := r1.Intn(10)
		sum += number * (10 - i)

		sb.WriteString(strconv.Itoa(number))
	}

	if sum%11 == 0 {
		digit := strconv.Itoa((11 - (sum % 11)))
		sb.WriteString(digit)
	} else {
		sb.WriteString("X")
	}

	return sb.String()

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
