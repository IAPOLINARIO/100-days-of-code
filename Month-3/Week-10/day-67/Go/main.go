package main

import (
	"fmt"
	"strings"
)

func main() {

	colorSequence := []string{"R", "W"}
	maze := [][]string{{"R", "O", "G"},
		{"W", "R", "W"},
		{"G", "O", "R"},
		{"O", "R", "W"}}

	fmt.Print(solveMaze(colorSequence, maze))
}

func solveMaze(colorSequence []string, maze [][]string) string {

	var sb strings.Builder
	currentColorIndex := 0
	for y := len(maze) - 1; y >= 0; y-- {
		colorFound := false
		for x := 0; x < len(maze[y]); x++ {
			if maze[y][x] == colorSequence[currentColorIndex] {
				sb.WriteString(fmt.Sprintf("(%v,%v)\n", x, y))
				currentColorIndex = getNextColorIndex(colorSequence, currentColorIndex)
				colorFound = true

				if (y+1) < len(maze) && maze[y+1][x] == colorSequence[currentColorIndex] { //looking up
					break
				}
			} else if x == len(maze[y])-1 && !colorFound {
				return fmt.Sprintln("NO SOLUTION!")
			}
		}
	}

	return sb.String()

}

func getNextColorIndex(colorSequence []string, currentIndex int) int {

	if currentIndex == len(colorSequence)-1 {
		return 0
	} else {
		return currentIndex + 1
	}
	return 0
}
