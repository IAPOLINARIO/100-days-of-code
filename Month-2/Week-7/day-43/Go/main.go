package main

import "fmt"

func main() {
	fmt.Println(triArea(3, 2))
}

func triArea(b, h int) int {
	return (b * h) / 2
}
