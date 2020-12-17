## Minesweeper

Minesweeper is a game where the objective is correctly identify the location of all mines in a given grid. You are given a uniform grid of gray squares in the beginning of the game. Each square contains either a mine (indicated by a value of 9), or an empty square. Empty squares have a number indicating the count of mines in the adjacent squares. Empty squares can have counts from zero (no adjacent mines) up to 8 (all adjacent squares are mines).

If you were to take a complete grid, for example, you can see which squares have mines and which squares are empty:

```
0  0  0  0  0
0  0  0  0  0
1  1  1  0  0
1  9  1  0  0
1  2  2  1  0
0  1  9  1  0
0  1  1  1  0
```

The squares with "2" indicate that there 2 mines adjacent to that particular square.

Gameplay starts with a user un-hiding a square at random. If the square contains a mine, the game ends. If it is a blank, the number of adjacent mines is revealed.

Exposing a zero means that there are no adjacent mines, so exposing all adjacent squares is guaranteed safe. As a convenience to the player, the game continues to expose adjacent squares until a non-zero square is reached.

For example, if you click on the top right corner you get this ('-' means hidden):

```
0  0  0  0  0
0  0  0  0  0
1  1  1  0  0
-  -  1  0  0
-  -  2  1  0
-  -  -  1  0
-  -  -  1  0
```

Write functions to construct the playing field given the size and number of mines.

### Tip

An important part of this problem is figuring out a way to place the mines. The most naive implementation is to pick two random numbers (row and column) and place a mine there, but this will cause the board to have less mines than expected if the same coordinates are picked twice. Re-trying if the picked coordinates already have a mine fixes the immediate problem, but will take a very long time for cases such as a 100x100 board with 9999 mines.
