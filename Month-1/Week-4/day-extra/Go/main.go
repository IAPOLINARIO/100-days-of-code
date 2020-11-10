package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {

	result := Solution(-999)

	fmt.Printf("Result: %v \n", result)
}

func Solution(N int) int {
	valueToAdd := "5"
	stringNumber := strconv.Itoa(N)
	arrayNumber := strings.Split(stringNumber, "")
	maxValue := N

	if N < 0 {
		resultString := "-" + valueToAdd + stringNumber[1:len(stringNumber)]
		finalResult, _ := strconv.Atoi(resultString)
		return finalResult
	} else if N == 0 {
		return 50
	} else {

		for i := 0; i < len(arrayNumber); i++ {
			sliceEnd := stringNumber[i+1 : len(stringNumber)]
			sliceBegin := stringNumber[0:i]
			currentChar := arrayNumber[i]

			digitBefore := sliceBegin + valueToAdd + currentChar + sliceEnd
			digitAfter := sliceBegin + currentChar + valueToAdd + sliceEnd

			firstPart, _ := strconv.Atoi(digitBefore)
			secondPart, _ := strconv.Atoi(digitAfter)

			if firstPart > maxValue {
				maxValue = firstPart
			} else if secondPart > maxValue {
				maxValue = secondPart
			}

		}
	}

	return maxValue
}

//got 2658 expected 5268
