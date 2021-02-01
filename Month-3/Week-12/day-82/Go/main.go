package main

import (
	"fmt"
)

func isNonDecreasing(number int64) bool {
	remainder := int64(10)

	for number > 0 {
		if number%10 <= remainder {
			remainder = number % 10
			number /= 10
		} else {
			return false
		}
	}

	return true
}

func lastTidyNumber(number int64) int64 {
	subtrahend := int64((number % 10) + 1)
	number -= subtrahend
	subtrahend = 10
	for !isNonDecreasing(number) {
		if number%(subtrahend*10) == (subtrahend*10)-1 {
			subtrahend *= 10
		}
		number -= subtrahend
	}
	return number
}

func CheckTidyNumber(input []int64) (result []string) {
	for i := int64(1); i <= input[0]; i++ {
		if isNonDecreasing(input[i]) {
			result = append(result, fmt.Sprintf("Case #%d: %d", i, input[i]))
		} else {
			result = append(result, fmt.Sprintf("Case #%d: %d", i, lastTidyNumber(input[i])))
		}
	}

	return result
}

func main() {
	input := []int64{4, 132, 1000, 7, 111111111111111110}

	fmt.Println(CheckTidyNumber(input))

}
