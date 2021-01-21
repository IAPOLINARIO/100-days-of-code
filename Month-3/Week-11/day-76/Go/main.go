package main

import (
	"fmt"
)

type Cake struct {
	weight      int
	value       int
	costBenefit float32
}

func (c *Cake) SetCostBenefit() float32 {
	if c.costBenefit == 0 {
		c.costBenefit = float32(c.value) / float32(c.weight)
	}

	return c.costBenefit
}

func main() {
	capacity := 20
	cakes := []Cake{{weight: 7, value: 160}, {weight: 3, value: 90}, {weight: 2, value: 15}}

	result := maxDuffelBagValue(cakes, capacity)
	fmt.Printf("Max capacity %d", result)

}

func maxDuffelBagValue(cakes []Cake, capacity int) int {

	calcCostBenefit(&cakes)

	for _, c := range cakes {
		fmt.Printf("Value Cake cost benefit 2: %v \n", c.costBenefit)
	}

	return 0
}

func calcCostBenefit(cakes *[]Cake) {
	for _, c := range *cakes {
		c.SetCostBenefit()
		fmt.Printf("Value Cake cost benefit 1: %v \n", c.costBenefit)
	}
}
