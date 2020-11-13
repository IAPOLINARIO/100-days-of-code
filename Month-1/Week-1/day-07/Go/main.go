package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Enter the first array:")

	input_1, _ := reader.ReadString('\n')

	fmt.Println("Enter the second array:")

	input_2, _ := reader.ReadString('\n')

	result, _ := MergeArrays(input_1, input_2)

	println(result)

}

func MergeArrays(input_1 string, input_2 string) (result string, err error) {

	var arr_1 []int
	var arr_2 []int
	var arr_3 []int

	_ = json.Unmarshal([]byte(input_1), &arr_1)
	_ = json.Unmarshal([]byte(input_2), &arr_2)

	sourceIndex := 0
	destIndex := 0

	for sourceIndex < len(arr_1) {
		if destIndex < len(arr_2) && (arr_1[sourceIndex] == 0 || arr_1[sourceIndex] > arr_2[destIndex]) {
			arr_3 = append(arr_3, arr_2[destIndex])
			destIndex += 1
			sourceIndex += 1
		} else if destIndex >= len(arr_2) || arr_1[sourceIndex] < arr_2[destIndex] {
			if arr_1[sourceIndex] > 0 {
				arr_3 = append(arr_3, arr_1[sourceIndex])
			}
			sourceIndex += 1
		} else if arr_1[sourceIndex] == arr_2[destIndex] {
			arr_3 = append(arr_3, arr_1[sourceIndex])
			arr_3 = append(arr_3, arr_2[destIndex])
			sourceIndex += 1
			destIndex += 1
		} else {
			sourceIndex += 1
		}
	}

	result = strings.Join(strings.Split(fmt.Sprint(arr_3), " "), ",")

	return result, err
}
