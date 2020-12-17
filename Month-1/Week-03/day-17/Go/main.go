package main

import "fmt"

func main() {

	cells := []int{1, 1, 0, 0, 0, 1, 0}

	result := freedPrisioner(cells)

	fmt.Printf("Freed prisioners: %v \n", result)

}

func freedPrisioner(cells []int) int {

	unLocked := true
	freedPresioners := 0

	if cells[0] != 0 {
		for i := 0; i < len(cells); i++ {
			if cells[i] == 1 && unLocked {
				freedPresioners += 1
				unLocked = false
			} else if cells[i] == 0 && !unLocked {
				freedPresioners += 1
				unLocked = true
			}
		}
	}

	return freedPresioners

}
