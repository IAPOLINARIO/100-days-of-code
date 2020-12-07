package main

import "fmt"

func main() {

	result := howManyGames(20, 3, 6, 80)

	fmt.Println(result)
}

func howManyGames(normalPrice, discount, minimumPrice, budget int) (gamesBought int) {

	lastGamePrice := normalPrice
	for {
		if gamesBought > 0 {
			if lastGamePrice-discount >= minimumPrice {
				lastGamePrice = lastGamePrice - discount
			}
		}

		if budget-lastGamePrice >= 0 {
			budget = budget - lastGamePrice
			gamesBought++
		} else {
			break
		}
	}

	return
}
