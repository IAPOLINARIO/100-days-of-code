package main

import "fmt"

func main() {

	word_1 := "car"
	word_2 := "rax"

	result := IsAnagram(word_1, word_2)

	fmt.Printf("Result is: %v \n", result)

}

func IsAnagram(wordOne string, wordTwo string) (result bool) {

	hashAnagram := make(map[string]int)

	if len(wordOne) != len(wordTwo) {
		result = false
	} else {
		result = true
		for i := 0; i < len(wordOne); i++ {
			charOne := string(wordOne[i])
			charTwo := string(wordTwo[i])

			if charOne != charTwo {
				hashAnagram[charOne] += 1
				hashAnagram[charTwo] -= 1
			}
		}

		for _, v := range hashAnagram {
			if v > 0 {
				result = false
				return result
			}
		}
	}

	return result
}
