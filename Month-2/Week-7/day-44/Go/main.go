package main

import "fmt"

func main() {
	fmt.Println(nextEdge(8, 10))
}

func nextEdge(s1, s2 int) int {
	return (s1 + s2) - 1
}
