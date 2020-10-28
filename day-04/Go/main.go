package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
)

func main() {

	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the progress days:\n")

	input, err := reader.ReadString('\n')

	if err != nil {
		fmt.Print("Something wrong happened")
	} else {
		result, _ := ProgressDays(input)

		fmt.Printf("Result: %v", result)
	}

}

func ProgressDays(inputDays string) (result int, err error) {

	var arr []int

	err = json.Unmarshal([]byte(inputDays), &arr)

	if err != nil {
		return result, fmt.Errorf("Something went wrong parsing the input...")
	}

	for i := 1; i < len(arr); i++ {
		if arr[i-1] < arr[i] {
			result += 1
		}
	}

	return result, err

}
