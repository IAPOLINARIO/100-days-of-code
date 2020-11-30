package main

import "fmt"

type Coin struct {
	value int
	used  bool
}

func (c *Coin) MarkAsUsed() {
	c.used = true
}

func main() {

	coins := []int{2, 4, 3, 2, 4, 9, 7, 8, 6, 9}
	result := coinsDiv(3, coins)

	fmt.Print(result)
}

func coinsDiv(numberOfKids int, coins []int) (result bool) {
	totalMoney, totalCoins := sumAndBuildCoins(coins)

	if totalMoney%numberOfKids == 0 {
		amountEachKidShouldReceive := totalMoney / numberOfKids
		totalBatches := 0
		currentBatch := 0

		for i := 0; i < len(totalCoins); i++ {
			if !totalCoins[i].used {
				currentBatch += totalCoins[i].value
				if currentBatch == amountEachKidShouldReceive {
					totalCoins[i].used = true
					totalBatches += 1
					currentBatch = 0
				} else {
					for j := i + 1; j < len(totalCoins); j++ {
						if !totalCoins[j].used {
							if currentBatch+totalCoins[j].value == amountEachKidShouldReceive {
								totalBatches += 1
								currentBatch = 0
								totalCoins[j].used = true
								break
							} else if currentBatch+totalCoins[j].value < amountEachKidShouldReceive {
								currentBatch += totalCoins[j].value
								totalCoins[j].used = true
							}
						}
					}
				}
			}
		}
		fmt.Printf("Total Batches: %v \n Total Money: %v \n Amount Each Kid: %v \n", totalBatches, totalMoney, amountEachKidShouldReceive)
		result = totalBatches == numberOfKids
	}

	return
}

func sumAndBuildCoins(inputCoins []int) (int, []Coin) {
	coins := []Coin{}
	sum := 0
	for _, v := range inputCoins {
		coin := Coin{value: v, used: false}
		coins = append(coins, coin)
		sum += v
	}

	return sum, coins
}
