package main

import "fmt"

func main() {

	var N int
	fmt.Scan(&N)

	var buf string
	var startX, startY int
	var finishX, finishY int
	for i := 0; i < N; i++ {
		fmt.Scan(&buf)
		for j := 0; j < N; j++ {
			switch string(buf[j]) {
			case "m":
				startX, startY = j, i
			case "p":
				finishX, finishY = j, i
			default:
			}
		}
	}

	switch MinMax(startY, finishY) {
	case 1:
		for i := startY; i > finishY; i-- {
			fmt.Println("UP")
		}
	case -1:
		for i := startY; i < finishY; i++ {
			fmt.Println("DOWN")
		}
	}

	switch MinMax(startX, finishX) {
	case 1:
		for i := startX; i > finishX; i-- {
			fmt.Println("LEFT")
		}
	case -1:
		for i := startX; i < finishX; i++ {
			fmt.Println("RIGHT")
		}
	}

}

func MinMax(a, b int) int {
	if a > b {
		return 1
	} else if a < b {
		return -1
	}
	return 0
}
