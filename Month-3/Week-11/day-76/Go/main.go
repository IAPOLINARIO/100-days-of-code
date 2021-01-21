package main

import "fmt"

type Cake struct {
	weight int
	value  int
}

func main() {

	capacity := 20
	cakes := []Cake{{weight: 7, value: 160}, {weight: 3, value: 90}, {weight: 2, value: 15}}

	result := maxDuffelBagValue(cakes, capacity)
	fmt.Printf("Max capacity %d", result)
}

func maxDuffelBagValue(cakes []Cake, capacity int) int {

	return 0
}
