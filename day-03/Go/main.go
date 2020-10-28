package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

const (
	vegan    = "o"
	nonvegan = "x"
)

func main() {

	reader := bufio.NewReader(os.Stdin)

	fmt.Printf("Enter the bbq configuration: \n")

	input, _ := reader.ReadString('\n')

	result, err := parseJson(input)

	if err != nil {
		fmt.Print(err)
	}

	fmt.Print(result)
}

func parseJson(input string) (result string, error error) {
	vegetarianSkewers := 0
	NonvegetarianSkewers := 0

	var SkewerArr []string
	err := json.Unmarshal([]byte(input), &SkewerArr)

	if err != nil {
		return result, fmt.Errorf("Something went wrong parsing the input !")
	}

	for _, s := range SkewerArr {
		if strings.Contains(s, nonvegan) {
			NonvegetarianSkewers += 1
		} else {
			if strings.Contains(s, vegan) {
				vegetarianSkewers += 1
			}
		}

	}

	result = fmt.Sprintf("[%v,%v]", vegetarianSkewers, NonvegetarianSkewers)

	return result, nil
}
