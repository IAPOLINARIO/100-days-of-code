package main

import "fmt"

func main() {
	fmt.Println(XOR(10, 41))
}

// function to swap two numbers  without
// using temporary variable and returns the subtraction of them
func XOR(x, y int) int {
	x = x ^ y
	y = x ^ y
	x = x ^ y

	return x - y
}
