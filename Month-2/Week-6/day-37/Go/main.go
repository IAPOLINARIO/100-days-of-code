package main

import (
	"fmt"
)

func main() {

	input := []int{10, 5, 20, 20, 4, 5, 2, 25, 1}

	fmt.Println("Result: " + breakingRecords(input))
}

func breakingRecords(records []int) (result string) {

	maxRecord := records[0]
	minRecord := records[0]
	maxCount := 0
	minCount := 0

	for _, v := range records {

		if v > maxRecord {
			maxRecord = v
			maxCount++
		} else if v < minRecord {
			minRecord = v
			minCount++
		}

	}
	result = fmt.Sprintf("[%v,%v]", maxCount, minCount)
	return
}
