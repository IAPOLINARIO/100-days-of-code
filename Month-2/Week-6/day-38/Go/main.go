package main

import "fmt"

func main() {

	keyboards := []int{40, 50, 60}
	drives := []int{5, 8, 12}
	budget := 60
	result := getMoneySpent(keyboards, drives, budget)

	fmt.Println(result)
}

func getMoneySpent(keyboardPrices, drivePrices []int, budget int) int {

	maxSpent := -1

	for _, k := range keyboardPrices {

		currentKeyboardPrice := k

		for _, d := range drivePrices {
			currentDrivePrice := d
			itemsCombinedPrice := currentKeyboardPrice + currentDrivePrice

			if itemsCombinedPrice <= budget && itemsCombinedPrice > maxSpent {
				maxSpent = itemsCombinedPrice
			}
		}

	}

	return maxSpent

}
