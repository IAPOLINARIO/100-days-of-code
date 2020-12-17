package main

import (
	"fmt"
	"strings"
)

const (
	columnSize        = 4
	scaleFactor       = 2
	verticalConnector = "|"
)

func main() {
	size := 1

	finalTop := ""
	finalMid := ""
	finalBot := ""

	for i := 0; i < 10; i++ {
		top, mid, bot := printLCD(i, size)
		finalTop += top + strings.Repeat(" ", columnSize*size)
		finalMid += mid + strings.Repeat(" ", columnSize*size)
		finalBot += bot + strings.Repeat(" ", columnSize*size)
	}

	fmt.Printf("%v\n%v\n%v\n\n", finalTop, finalMid, finalBot)

}

func printLCD(number, size int) (top, mid, bot string) {

	switch number {
	case 0:
		return printZero(size)
	case 1:
		return printOne(size)
	case 2:
		return printTwo(size)
	case 3:
		return printThree(size)
	case 4:
		return printFour(size)
	case 5:
		return printFive(size)
	case 6:
		return printSix(size)
	case 7:
		return printSeven(size)
	case 8:
		return printEight(size)
	case 9:
		return printNine(size)

	}

	return
}

func printZero(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := "|  |"
	bot := "|__|"

	return buildNumber(top, mid, bot, size)
}

func printOne(size int) (resultTop, resultMid, resultBot string) {
	top := "   "
	mid := "  |"
	bot := "  |"

	return buildNumber(top, mid, bot, size)
}

func printTwo(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := " __|"
	bot := "|__ "

	return buildNumber(top, mid, bot, size)
}

func printThree(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := " __|"
	bot := " __|"

	return buildNumber(top, mid, bot, size)
}

func printFour(size int) (resultTop, resultMid, resultBot string) {
	top := "   "
	mid := "|_|"
	bot := "  |"

	return buildNumber(top, mid, bot, size)
}

func printFive(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := "|__ "
	bot := " __|"

	return buildNumber(top, mid, bot, size)
}

func printSix(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := "|__ "
	bot := "|__|"

	return buildNumber(top, mid, bot, size)
}

func printSeven(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := "   |"
	bot := "   |"

	return buildNumber(top, mid, bot, size)
}

func printEight(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := "|__|"
	bot := "|__|"

	return buildNumber(top, mid, bot, size)
}

func printNine(size int) (resultTop, resultMid, resultBot string) {
	top := " __ "
	mid := "|__|"
	bot := "   |"

	return buildNumber(top, mid, bot, size)
}

func buildNumber(top, mid, bot string, size int) (resultTop, resultMid, resultBot string) {
	resultTop = rescaleNumber(top, size)
	resultMid = rescaleNumber(mid, size)
	resultBot = rescaleNumber(bot, size)

	return //fmt.Sprintf("%v\n%v\n%v", finalTop, finalMid, finalBot)
}

func rescaleNumber(numberPart string, size int) (result string) {

	if size > 1 {
		blankSpacesAtLeft := 0
		if strings.TrimSpace(numberPart) == "" {
			result = repeatChar(numberPart, blankSpacesAtLeft, true, size)
		} else if strings.TrimSpace(numberPart) == "|" {
			blankSpacesAtLeft = (size * scaleFactor) - 1
			result = repeatChar(numberPart, blankSpacesAtLeft, true, size)
		} else if strings.TrimSpace(numberPart) == "__" {
			result = fmt.Sprintf("%v ", repeatChar(strings.TrimSpace(numberPart), blankSpacesAtLeft, false, size))
		} else if numberPart == " __|" {
			side := repeatChar("|", size*scaleFactor, true, size-1)
			base := repeatChar("__", blankSpacesAtLeft, false, size) + verticalConnector
			result = fmt.Sprintf("%v%v", side, base)
		} else if numberPart == "|__ " {
			side := repeatChar("|", blankSpacesAtLeft, true, size-1)
			base := verticalConnector + repeatChar("__", blankSpacesAtLeft, false, size)
			result = fmt.Sprintf("%v%v", side, base)
		} else if numberPart == "|_|" || numberPart == "|__|" {
			sides := repeatCharWithSpaceInBetween("|", size*scaleFactor, size-1)
			base := verticalConnector + repeatChar("__", blankSpacesAtLeft, false, size) + verticalConnector
			result = fmt.Sprintf("%v%v", sides, base)
		}
	} else {
		return numberPart
	}

	return
}
func repeatCharWithSpaceInBetween(character string, spacesQty, size int) (result string) {
	spaces := strings.Repeat(" ", spacesQty)
	for i := 0; i < size; i++ {
		result += fmt.Sprintf("%v%v%v\n", character, spaces, character)
	}

	return
}

func repeatChar(character string, numberOfBlankSpacesInTheLeft int, breakLine bool, repeat int) string {
	var sb strings.Builder
	blankSpacesInTheLeftSide := strings.Repeat(" ", numberOfBlankSpacesInTheLeft)
	if breakLine {
		for i := 0; i < repeat; i++ {
			sb.WriteString(fmt.Sprintf("%v%v\n", blankSpacesInTheLeftSide, character))
		}
	} else {
		sb.WriteString(blankSpacesInTheLeftSide + strings.Repeat(character, repeat))
	}

	return sb.String()
}
