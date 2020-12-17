package main

import (
	"strconv"
	"strings"
)

func main() {

	invalid2 := "5,4,3,2,1"
	arrayInput := strings.Split(invalid2, ",")

	println(LandscapeType(arrayInput))

}

func LandscapeType(input []string) (result string) {
	isLeftIncreasing := true
	isRigthIncreasing := false
	peak := 0
	trough := 0
	troughCount := 0
	peakCount := 0
	isBoundary := false

	for i := 1; i < len(input); i++ {
		currentValue, _ := strconv.Atoi(input[i])
		previousValue, _ := strconv.Atoi(input[i-1])

		if currentValue > previousValue {
			if isLeftIncreasing && !isRigthIncreasing {
				if peakCount == 0 {
					peakCount += 1
					peak = currentValue
				} else if currentValue > peak {
					peak = currentValue
				}
			} else if !isLeftIncreasing && isRigthIncreasing {
				if currentValue > peak {
					peakCount += 1
					peak = currentValue
					if peakCount > 1 || troughCount > 1 {
						isBoundary = true
					} else {
						isBoundary = false
					}

				} else if currentValue > trough {
					peakCount += 1
					isBoundary = false
				}

			}
		} else if currentValue < previousValue {
			if i-1 == 0 {
				peak = previousValue
				isLeftIncreasing = false
				isRigthIncreasing = true
				trough = currentValue
				troughCount += 1
				peakCount += 1
				isBoundary = true
			} else if isLeftIncreasing && !isRigthIncreasing {
				trough = currentValue
				isRigthIncreasing = true
				isLeftIncreasing = false
				troughCount += 1
			} else if !isLeftIncreasing && isRigthIncreasing && currentValue < trough {
				if troughCount == 0 {
					troughCount += 1
				}
				trough = currentValue
			}
		}
	}

	if peakCount == 1 && !isBoundary {
		result = "mountain"
	} else if troughCount == 1 && !isBoundary {
		result = "valley"
	} else if peakCount > 1 || troughCount > 1 || isBoundary {
		result = "neither"
	}

	return result
}
