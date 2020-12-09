# Color maze

Today we are going to do something colorfull and amazing. Yes it is a color maze :D (you can downvote me now, it was totally worth it).

You traverse a color by following a sequence of colors. For example this maze can be solved by the sequence 'orange -> green':

<p align="center">
  <img src="../../../assets/maze_color_1.png" alt="maze color">
</p>

Then you would have something like this (paint skills):

<p align="center">
  <img src="../../../assets/maze_color_2.png" alt="maze color solution">
</p>

For the mazes you always pick a spot on the bottom, in the starting color and try to get to the first row. Once you reach the first row, you are out of the maze. The sequence does not have to be complete.

You can move horizontally and vertically, but not diagonally. It is also allowed to move on the same node more then once.

## Objective

Write a function with **two input parameters**:
- Sequence of colors to follow as a array/vector of chars
- The maze as a array/vector of chars

## Output
The path in the maze as coordinates x, y.

## Example
```text
colorMaze([O, G],
          [B O R O Y
           O R B G R
           B O G O Y 
           Y G B Y G 
           R O R B R])  ➞ [(1,4),(1,3),(1,2),(2,2),(3,2),(3,1),(3,0)]
```
