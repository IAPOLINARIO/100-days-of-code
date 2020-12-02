package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	result := carryOperations(545, 555)

	fmt.Println(result)
}

func carryOperations(num1, num2 int) (carryOperations int) {

	stringNum1 := strconv.Itoa(num1)
	stringNum2 := strconv.Itoa(num2)

	if len(stringNum1) > len(stringNum2) {
		charDifference := len(stringNum1) - len(stringNum2)
		stringNum2 = strings.Repeat("0", charDifference) + stringNum2
	} else if len(stringNum2) > len(stringNum1) {
		charDifference := len(stringNum2) - len(stringNum1)
		stringNum1 = strings.Repeat("0", charDifference) + stringNum1
	}
	exceeded := 0
	for i := len(stringNum1) - 1; i >= 0; i-- {

		NumOnecurrentDigit, _ := strconv.Atoi(string(stringNum1[i]))
		NumTwocurrentDigit, _ := strconv.Atoi(string(stringNum2[i]))
		currentSum := NumOnecurrentDigit + NumTwocurrentDigit + exceeded

		if currentSum >= 10 {
			carryOperations++
			exceeded = currentSum - 9
		} else {
			exceeded = 0
		}

	}

	return
}
