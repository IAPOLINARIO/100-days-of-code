package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
)

type bbqSkewers struct {
	skewer string
}

func main() {

	reader := bufio.NewReader(os.Stdin)

	fmt.Printf("Enter the bbq configuration: \n")

	input, err := reader.ReadString('\n')

	if err != nil {
		fmt.Printf("Sorry, but something went wrong: %v", err)
	} else {
		parseJson(input)
	}

}

func parseJson(input string) {

	staticInput := `bbqSkewers([
  					"--oooo-ooo--",
  					"--xx--x--xx--",
  					"--o---o--oo--",
  					"--xx--x--ox--",
  					"--xx--x--ox--"
					])`

	var skewers []bbqSkewers
	json.Unmarshal([]byte(staticInput), &skewers)

	fmt.Printf("Skewers: %+v", staticInput)
}

// bbqSkewers([
// 	"--oooo-ooo--",
// 	"--xx--x--xx--",
// 	"--o---o--oo--",
// 	"--xx--x--ox--",
// 	"--xx--x--ox--"
//   ])
