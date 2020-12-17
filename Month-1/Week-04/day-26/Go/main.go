package main

import (
	"fmt"
	"strconv"
)

const (
	lockerSides = 10
)

func main() {

	//result := minTurns("4089", "5672")
	//result := minTurns("1111", "1100")
	//result := minTurns("4389", "5972")
	result := minTurns("2391", "4984")
	fmt.Println(result)

}

func minTurns(currentLock, targetLock string) (turns int) {

	for i := 0; i < len(currentLock); i++ {

		currentTurns := 0
		cl, _ := strconv.Atoi(string(currentLock[i]))
		tl, _ := strconv.Atoi(string(targetLock[i]))

		if cl <= tl {
			currentTurns = tl - cl

		} else {
			currentTurns = cl - tl
		}

		if currentTurns >= lockerSides/2 { //use backwards
			currentTurns = lockerSides - currentTurns
		}

		turns += currentTurns
	}
	return
}
