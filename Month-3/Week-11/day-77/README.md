## Bot saves princess

In this version of "Bot saves princess", Princess Peach and bot's position are randomly set. Can you save the princess?

### Task

Create a function nextMove which takes in 4 parameters - an integer N, integers r and c indicating the row & column position of the bot and the character array grid - and outputs the next move the bot makes to rescue the princess.

### Input Format

The first input parameter is N (<100), the size of the board (NxN). The second and third parameters of the input represents the position of the bot.

Grid is indexed using Matrix Convention

The position of the princess is indicated by the character 'p' and the position of the bot is indicated by the character 'm' and each cell is denoted by '-' (ascii value: 45).

### Output Format

Output the shortest path you take to rescue the princess. Valid moves are LEFT, RIGHT, UP or DOWN

#### Sample Input

```
5,2,3
-----
-----
p--m-
-----
-----
```

#### Sample Output

```
LEFT, LEFT, LEFT
```
