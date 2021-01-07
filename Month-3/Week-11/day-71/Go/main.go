package main

import (
	"fmt"
	"math/bits"
)

func main() {
	input := [][]int{{2, 4}, {3, 6}, {1, 3}, {6, 8}}

	fmt.Println(lightsOn(input))
}

func lightsOn(lights [][]int) int {
	var u, n uint
	for _, light := range lights {

		t1 := light[0]
		t2 := light[1]

		//, storing the hours as 1-bits, then count the number of 1-bits at the end.
		n = (1 << t2) - (1 << t1)
		u |= n
	}

	return bits.OnesCount(u)
}
