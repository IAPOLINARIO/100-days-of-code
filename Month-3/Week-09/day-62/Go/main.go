package main

import "fmt"

func main() {

	fmt.Println(harvest(50000, 1))

}

func harvest(peopleToFeed, plants int) int {

	fruits := 0
	weeksElapsed := 1

	for peopleToFeed >= 0 {
		fruits = plants + fruits
		peopleToFeed = peopleToFeed - fruits

		fruits = 0
		fruits = plants * weeksElapsed
		plants = plants * 2
		weeksElapsed++
	}

	return weeksElapsed
}
