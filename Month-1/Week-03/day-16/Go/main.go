package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Printf("Enter the number of stones: ")

	input, _ := reader.ReadString('\n')
	stones, _ := strconv.Atoi(strings.TrimSpace(input))

	fmt.Printf("Possibility of winning: %v \n", canWin(stones))
}

func canWin(stones int) bool {
	return stones%4 != 0
}
