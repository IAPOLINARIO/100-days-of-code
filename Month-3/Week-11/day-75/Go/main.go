package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

// Grid is playground.
type Grid [][]Cell

// CellsStat contains info about cells.
type CellsStat struct {
	Bombs, Free int
}

// Cell constants
const (
	Bomb     = Cell(9)
	Unfolded = Cell(1 << 4)
	Flagged  = Cell(1 << 5)
)

// Cell contains cell's state.
type Cell byte

// IsBomb checks does a cell contain a bomb
func (c Cell) IsBomb() bool {
	return c.same(Bomb)
}

// Bombs returns bombs suggestions.
func (c Cell) Bombs() byte {
	return byte(c &^ (Flagged | Unfolded))
}

// Unfolded checks that a cell is open.
func (c Cell) Unfolded() bool {
	return c.same(Unfolded)
}

func (c Cell) any(t Cell) bool {
	return c&t > 0
}

func (c Cell) same(t Cell) bool {
	return c&t == t
}

func (c *Cell) unfold() {
	c.Flag(false)
	*c |= Unfolded
}

func (c *Cell) suggest(bombs byte) {
	*c |= Cell(bombs)
}

// Flagged checks that a cell has a flag.
func (c Cell) Flagged() bool {
	return c.same(Flagged)
}

// Flag sets or unsets a flag on the cell.
func (c *Cell) Flag(enable bool) {
	if c.Unfolded() {
		return
	}
	if enable {
		*c |= Flagged
	} else {
		*c &^= Flagged
	}
}

func main() {
	rows := 10
	cols := 10
	// fmt.Print("Enter [rows cols]: ")
	// if _, err := fmt.Fscan(os.Stdin, &rows, &cols); err != nil {
	// 	fmt.Println("failed to read rows & cols:", err)
	// 	return
	// }
	rand.Seed(time.Now().UnixNano())
	m := GenerateGrid(rows, cols, 0.3)
	//g := minesweeper.New(m)
	printGrid(m)

}

func printGrid(m Grid) {
	for _, r := range m {
		for _, c := range r {
			//if c.Unfolded() {
			if c.IsBomb() {
				fmt.Print("x")
			} else {
				fmt.Print(c.Bombs())
			}
			//} else if c.Flagged() {
			//	fmt.Print("F")
			//} else {
			//	fmt.Print("#")
			//}
			fmt.Print(" ")
		}
		fmt.Printf("\n")
	}
}

func newGrid(rows, cols int) Grid {
	m := make(Grid, rows)
	for i := range m {
		m[i] = make([]Cell, cols)
	}
	return m
}

// GenerateGrid creates a matrix with randomly distributed bombs.
// rand.Seed should be run manually before GenerateGrid call.
func GenerateGrid(rows, cols int, diffc float64) Grid {
	cells := rows * cols
	bombs := int(math.Ceil(float64(cells) * diffc))
	m := newGrid(rows, cols)
	var offset int
	for bombs > 0 {
		offset += rand.Intn(rand.Intn(cells-offset-bombs) + 1)
		i := offset / cols
		j := offset % cols
		m[i][j] = Bomb
		bombs--
		offset++
	}
	return m
}
