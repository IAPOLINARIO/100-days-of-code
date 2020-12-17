package main

import "fmt"

const (
	tie       = "#"
	playerOne = "X"
	playerTwo = "O"
)

func main() {

	input := [][]string{
		{"X", "O", "O"},
		{"O", "X", "O"},
		{"O", "#", "X"}}

	fmt.Println(ticTacToe(input))
}

func ticTacToe(game [][]string) string {

	resultTable := make(map[string]int)

	resultTable[playerOne] = 0
	resultTable[playerTwo] = 0

	for i := 0; i < len(game); i++ {
		rowWinner := checkRoundWinner(game[i][0], game[i][1], game[i][2])
		resultTable[rowWinner]++

		columnWinner := checkRoundWinner(game[0][i], game[1][i], game[2][i])
		resultTable[columnWinner]++
	}

	diagonalOneWinner := checkRoundWinner(game[0][0], game[1][1], game[2][2])
	resultTable[diagonalOneWinner]++

	diagonalTwoWinner := checkRoundWinner(game[2][0], game[1][1], game[0][2])
	resultTable[diagonalTwoWinner]++

	return checkGameWinner(resultTable)

}

func checkGameWinner(gameResult map[string]int) string {
	if gameResult[playerOne] > gameResult[playerTwo] {
		return "Player 1 wins"
	} else if gameResult[playerOne] < gameResult[playerTwo] {
		return "Player 2 wins"
	}

	return "It's a Tie"
}

func checkRoundWinner(val1, val2, val3 string) string {
	playerOneWon := playerWins(val1, val2, val3, playerOne)
	playerTwoWon := playerWins(val1, val2, val3, playerTwo)

	if playerOneWon {
		return playerOne
	} else if playerTwoWon {
		return playerTwo
	}

	return tie
}

func playerWins(val1, val2, val3, player string) bool {

	if val1 == player && val2 == player && val3 == player {
		return true
	}
	return false
}
