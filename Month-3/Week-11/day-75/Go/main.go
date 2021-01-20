package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type cell struct {
	isMine  bool
	display byte // display character for cell
}

const lMargin = 4

var (
	grid        [][]cell
	mineCount   int
	minesMarked int
	isGameOver  bool
)

func makeGrid(n, m int) {
	if n <= 0 || m <= 0 {
		panic("Grid dimensions must be positive.")
	}
	grid = make([][]cell, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]cell, m)
		for j := 0; j < m; j++ {
			grid[i][j].display = '.'
		}
	}
	min := int(math.Round(float64(n*m) * 0.1)) // 10% of tiles
	max := int(math.Round(float64(n*m) * 0.2)) // 20% of tiles
	mineCount = min + rand.Intn(max-min+1)
	rm := mineCount
	for rm > 0 {
		x, y := rand.Intn(n), rand.Intn(m)
		if !grid[x][y].isMine {
			rm--
			grid[x][y].isMine = true
		}
	}
	minesMarked = 0
	isGameOver = false
}

func displayGrid() {
	fmt.Println("Grid has", mineCount, "mine(s)")
	fmt.Println()
	for y := 0; y < len(grid[0]); y++ {
		for x := 0; x < len(grid); x++ {
			fmt.Printf("%c", grid[x][y].display)
		}
		fmt.Println()
	}
}

func countAdjMines(x, y int) int {
	count := 0
	for j := y - 1; j <= y+1; j++ {
		if j >= 0 && j < len(grid[0]) {
			for i := x - 1; i <= x+1; i++ {
				if i >= 0 && i < len(grid) {
					if grid[i][j].isMine {
						count++
					}
				}
			}
		}
	}
	return count
}

func clearCell(x, y int) bool {
	if x >= 0 && x < len(grid) && y >= 0 && y < len(grid[0]) {
		if grid[x][y].display == '.' {
			if !grid[x][y].isMine {
				count := countAdjMines(x, y)
				if count > 0 {
					grid[x][y].display = string(48 + count)[0]
				} else {
					grid[x][y].display = '0'
					clearCell(x+1, y)
					clearCell(x+1, y+1)
					clearCell(x, y+1)
					clearCell(x-1, y+1)
					clearCell(x-1, y)
					clearCell(x-1, y-1)
					clearCell(x, y-1)
					clearCell(x+1, y-1)
				}
			} else {
				grid[x][y].display = '9'
			}
		}
	}
	return true
}

func revealCells() {
	for x := 0; x < len(grid); x++ {
		for y := 0; y < len(grid[x]); y++ {
			clearCell(x, y)
		}

	}
}

func main() {
	rand.Seed(time.Now().UnixNano())
	makeGrid(7, 5)
	revealCells()
	displayGrid()

}
