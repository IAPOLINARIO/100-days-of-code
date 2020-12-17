# Tic Tac Toe

Create a function that takes an array of char inputs from a _Tic Tac Toe_ game. Inputs will be taken from player1 as **"X"**, player2 as **"O"**, and empty spaces as **"#"**. The program will return the winner or tie results.

## Examples
```text
ticTacToe([
  ["X", "O", "O"],
  ["O", "X", "O"],
  ["O", "#", "X"]
]) ➞ "Player 1 wins"

ticTacToe([
  ["X", "O", "O"],
  ["O", "X", "O"],
  ["X", "#", "O"]
]) ➞ "Player 2 wins"

ticTacToe([
  ["X", "X", "O"],
  ["O", "X", "O"],
  ["X", "O", "#"]
]) ➞ "It's a Tie"
```