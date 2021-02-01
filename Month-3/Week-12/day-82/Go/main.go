package main

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
