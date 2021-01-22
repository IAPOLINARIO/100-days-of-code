package main

import (
	"fmt"
	"sort"
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

type ByCostBenefit []Cake

func (c ByCostBenefit) Len() int {
	return len(c)
}

func (c ByCostBenefit) Less(i, j int) bool {
	return c[j].costBenefit < c[i].costBenefit
}

func (c ByCostBenefit) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

func main() {
	capacity := 20
	cakes := []Cake{{weight: 7, value: 160}, {weight: 3, value: 90}, {weight: 2, value: 15}}

	result := maxDuffelBagValue(cakes, capacity)
	fmt.Printf("Max capacity %d", result)

}

func maxDuffelBagValue(cakes []Cake, capacity int) int {

	calcCostBenefit(cakes)
	sort.Sort(ByCostBenefit(cakes))

	currentLoad := 0
	currentValue := 0
	for _, c := range cakes {
		for currentLoad+c.weight <= capacity {
			currentLoad += c.weight
			currentValue += c.value
		}
	}

	fmt.Printf("Total Load: %v \n", currentLoad)

	return currentValue
}

func calcCostBenefit(cakes []Cake) {
	for i, _ := range cakes {
		c := &cakes[i]
		c.SetCostBenefit()
		//fmt.Printf("Value Cake cost benefit 1: %v \n", c.costBenefit)
	}
}
