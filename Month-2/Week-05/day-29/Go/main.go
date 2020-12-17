package main

import (
	"fmt"
	"strings"
)

func main() {
	//input := "R G Y R C R G Y R"
	input2 := "G Y R G Y R"

	result := trafficLightChecker(strings.Split(input2, " "))

	fmt.Println(result)

}

func trafficLightChecker(input []string) string {

	if len(input) > 15 || input[0] != "R" {
		return "REJECT"
	}

	for i := 0; i < len(input); i++ {
		currentValue := input[i]
		nextValue := ""

		if i+1 < len(input) {
			nextValue = input[i+1]
		}

		if !isPartOfTheGrammar(currentValue) {
			return "ERROR"
		} else if input[i] == "R" {
			if !strings.Contains("GPC", nextValue) {
				return "ERROR"
			}
		} else if input[i] == "G" {
			if !strings.Contains("Y", nextValue) {
				return "ERROR"
			}
		} else if input[i] == "Y" {
			if !strings.Contains("R", nextValue) {
				return "ERROR"
			}
		}
	}

	return "CORRECT"
}

func isPartOfTheGrammar(currentValue string) bool {

	grammar := []string{"R", "Y", "G", "P", "C", "X"}

	for _, v := range grammar {
		if currentValue == v {
			return true
		}
	}
	return false
}
