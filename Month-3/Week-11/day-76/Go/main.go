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

func (c *Cake) GetCostBenefit() float32 {
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
	return c[i].costBenefit < c[j].costBenefit
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
	calcAndSortCostBenefit(&cakes)

	for _, c := range cakes {
		fmt.Printf("Cake cost benefit: %f \n", c.costBenefit)
	}

	return 0
}

func calcAndSortCostBenefit(cakes *[]Cake) {
	for _, c := range *cakes {
		c.GetCostBenefit()
	}

	sort.Sort(ByCostBenefit(*cakes))
}
