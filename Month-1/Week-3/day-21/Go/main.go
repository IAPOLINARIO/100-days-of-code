package main

import (
	"bytes"
	"fmt"
	"math/rand"
	"time"
)

type Maze struct {
	c, h, v                    []byte
	cell, horizontal, vertical [][]byte
}

const (
	up = iota
	down
	right
	left
)

func main() {
	d := DrawMaze(4, 4)
	d.generator()
	fmt.Print(d)
}

func DrawMaze(rows, cols int) *Maze {
	c := make([]byte, rows*cols) //total number of cells

	h := bytes.Repeat([]byte{'-'}, rows*cols) //horizontal separator

	v := bytes.Repeat([]byte{'|'}, rows*cols) //vertical walls

	cell := make([][]byte, rows)
	horizontal := make([][]byte, rows)
	vertical := make([][]byte, rows)

	for i := range horizontal {
		cell[i] = c[i*cols : (i+1)*cols]
		horizontal[i] = h[i*cols : (i+1)*cols]
		vertical[i] = v[i*cols : (i+1)*cols]
	}

	return &Maze{c, h, v, cell, horizontal, vertical}
}

func (m *Maze) String() string {
	hWall := []byte("+---")
	hOpen := []byte("+   ")
	vWall := []byte("|   ")
	vOpen := []byte("    ")
	rightCorner := []byte("+\n")
	rightWall := []byte("|\n")
	var b []byte
	// for all rows
	for r, hw := range m.horizontal {
		// draw h walls
		for _, h := range hw {
			if h == '-' || r == 0 {
				b = append(b, hWall...)
			} else {
				b = append(b, hOpen...)
			}
		}
		b = append(b, rightCorner...)
		// draw v walls
		for c, vw := range m.vertical[r] {
			if vw == '|' || c == 0 {
				b = append(b, vWall...)
			} else {
				b = append(b, vOpen...)
			}
			// draw cell contents
			if m.cell[r][c] != 0 {
				b[len(b)-2] = m.cell[r][c]
			}
		}
		b = append(b, rightWall...)
	}
	// draw bottom edge of maze
	for _ = range m.horizontal[0] {
		b = append(b, hWall...)
	}
	b = append(b, rightCorner...)
	return string(b)
}

func (m *Maze) generator() {
	// Allocate the maze with recursive method
	m.recursion(rand.Intn(len(m.cell)), rand.Intn(len(m.cell[0])))
}

func (m *Maze) recursion(row, col int) {
	rand.Seed(time.Now().UnixNano())
	m.cell[row][col] = ' '

	for _, wall := range rand.Perm(4) {
		switch wall {
		//　Whether cells up is out or not
		case up:
			if row > 0 && m.cell[row-1][col] == 0 {
				m.horizontal[row][col] = 0
				m.recursion(row-1, col)
			}
		// Whether cells down is out or not
		case down:
			if row < len(m.cell)-1 && m.cell[row+1][col] == 0 {
				m.horizontal[row+1][col] = 0
				m.recursion(row+1, col)
			}
		// Whether cells left is out or not
		case left:
			if col > 0 && m.cell[row][col-1] == 0 {
				m.vertical[row][col] = 0
				m.recursion(row, col-1)
			}
		// Whether cells to the right is out or not
		case right:
			if col < len(m.cell[0])-1 && m.cell[row][col+1] == 0 {
				m.vertical[row][col+1] = 0
				m.recursion(row, col+1)
			}
		}
	}
}
