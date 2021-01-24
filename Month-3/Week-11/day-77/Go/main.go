package main

import "fmt"

func nextMove(n, c, r int, grid [][]string) {
	var up, left int
	princess := [2]int{}

	/* find the princess */

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == "p" {
				princess[0] = i
				princess[1] = j
			}
		}
	}

	up = princess[0] - r
	if up < 0 {
		fmt.Printf("UP\n")
		return
	} else if up > 0 {
		fmt.Printf("DOWN\n")
		return
	}

	left = princess[1] - c
	if left < 0 {
		fmt.Printf("LEFT\n")
		return
	} else if left > 0 {
		fmt.Printf("RIGHT\n")
		return
	}
}

/* Tail starts here */
func main() {

	n := 5
	x := 2
	y := 3

	grid := [][]string{{"-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-"}, {"p", "-", "-", "m", "-"}, {"-", "-", "-", "-", "-"}, {"-", "-", "-", "-", "-"}}

	nextMove(n, x, y, grid)
}

/*
-----
-----
p--m-
-----
*/
