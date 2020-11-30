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
	staticValue := 50
	stringNumber := strconv.Itoa(N)
	arrayNumber := strings.Split(stringNumber, "")
	maxValue := N

	if N < 0 {
		resultString := "-" + valueToAdd + stringNumber[1:len(stringNumber)]
		finalResult, _ := strconv.Atoi(resultString)
		return finalResult
	} else if N == 0 {
		return staticValue
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

// Optmized solution found on internet
// forming of the formula:
// newVal = ((num / position) * (position * 10)) + (digit * position) + (num % position)

// suppose, num = 276, starting from position = 1, and the digit = 3.

// number will be in three parts: [left of 3] + [3] + [right of 3]

// step 1: ((276/1) * (1*10)) + (3*1) + (276%1) = [2760]+[3]+[0] = [2763]
// step 2: ((276/10) * (10*10)) + (3*10) + (276%10) = [2700]+[30]+[6] = [2736]
// step 3: ((276/100) * (100*10)) + (3*100) + (276%100) = [2000]+[300]+[76] = [2376]
// step 4: ((276/1000) * (1000*10)) + (3*1000) + (276%1000) = [0]+[3000]+[276] = [3276]
