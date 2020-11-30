package main

import (
	"fmt"
	"os"
	"strconv"
)

func CalcAge(age int) int {
	return age * 365
}

func main() {
	usage := fmt.Sprintf("Usage: %s <age>\n", os.Args[0])
	if len(os.Args) < 2 {
		fmt.Print(usage)
		return
	}
	age, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Print(usage)
		return
	}
	fmt.Println(CalcAge(age))
}
