package main

import (
	"fmt"
	"strings"

	"github.com/fatih/color"
)

const (
	treeBuildingBlock = "#"
)

func main() {
	fmt.Print(buildChristmasTree(10))
}

func buildChristmasTree(height int) (result string) {
	treeWidth := height + (height - 1)
	blocks := ""
	blocksQty := 0
	spacesQty := 0

	for i := 1; i <= height; i++ {
		blocksQty = i + (i - 1)
		spacesQty = (treeWidth - blocksQty) / 2
		if i == 1 {
			blocks = color.YellowString(strings.Repeat(treeBuildingBlock, blocksQty))
		} else {
			blocks = color.GreenString(strings.Repeat(treeBuildingBlock, blocksQty))
		}

		side := strings.Repeat(" ", spacesQty)

		result += fmt.Sprintf("%v%v%v\n", side, blocks, side)
	}

	return
}
