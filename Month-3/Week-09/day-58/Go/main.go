package main

import (
	"fmt"
	"math/rand"
	"regexp"
	"strconv"
)

func main() {

	input := []string{"3d6", "4d12", "1d10", "5d4"}
	seed := int64(10) //time.Now().UnixNano()
	rollTheDices(input, seed)

}

func rollTheDices(dices []string, seed int64) (result []string) {

	regexSides := regexp.MustCompile(`[^d]*$`)
	regexRoll := regexp.MustCompile(`[^d]*`)
	rand.Seed(seed)

	for _, dice := range dices {
		diceSides, _ := strconv.Atoi(regexSides.FindString(dice))
		rollTimes, _ := strconv.Atoi(regexRoll.FindString(dice))
		randomNumber := 0
		sum := 0
		currentResult := ""

		for i := 0; i < (rollTimes - 1); i++ {
			randomNumber = rand.Intn(diceSides-1) + 1
			sum += randomNumber
			currentResult += fmt.Sprintf("%d ", randomNumber)
		}
		randomNumber = rand.Intn(diceSides-1) + 1
		sum += randomNumber
		currentResult = fmt.Sprintf("%d: %v %d\n", sum, currentResult, randomNumber)
		fmt.Print(currentResult)
		result = append(result, currentResult)
	}
	return
}
