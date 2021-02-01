package main

import "fmt"

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

func main() {
	input := []int64{4, 132, 1000, 7, 111111111111111110}

	for i := int64(1); i <= input[0]; i++ {
		if isNonDecreasing(input[i]) {
			fmt.Printf("Case #%d: %d \n", i, input[i])
		} else {
			fmt.Printf("Case #%d: %d \n", i, lastTidyNumber(input[i]))
		}
	}

}
