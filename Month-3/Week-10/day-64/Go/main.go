package main

import "fmt"

func main() {
	input := "ABCDEBC"

	fmt.Println(checkRecurrence(input))
}

func checkRecurrence(input string) string {
	recurrenceMap := make(map[string]int)
	for _, c := range input {
		recurrenceMap[string(c)] += 1
		if recurrenceMap[string(c)] == 2 {
			return string(c)
		}
	}
	return ""
}
