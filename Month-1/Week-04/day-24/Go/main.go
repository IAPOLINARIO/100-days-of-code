package main

import "fmt"

func finalSurvivor(n, k int) int {
	circle := make([]int, n)
	for i := range circle {
		circle[i] = i
	}
	k--
	exPos := 0
	for len(circle) > 1 {
		exPos = (exPos + k) % len(circle)
		circle = append(circle[:exPos], circle[exPos+1:]...)
	}
	return circle[0] + 1
}

func main() {
	fmt.Println(finalSurvivor(11, 1))
}
