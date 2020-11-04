## COVID spread

You are given a 2D array of people, where `1` represents someone with the virus, and `0` represents someone without the virus. Every day, the people with the virus infect their neighbours. You must calculate, given such a grid, how many days it will take to infect the population (i.e., every item is `1`).

### Rules

- The input counts as Day 0, and every day after increases by 1 (you can count the first day as Day 1 if you want, but indicate that in your answer).
- The grid items don't have to be `1`s and `0`s, they can be any truthy/falsy values. Every item in the grid is randomized to one of those values. Please specify which truthy/falsy values your program will/will not accept.
- The input grid can be any size between 2x2 and 100x100. The grid does not have to be square. The grid size is randomized (i.e. you can't choose).
- Diagonal squares do not count as adjacent.

## Examples

```text
[[1, 0, 0, 0, 1],  # Input
 [0, 1, 0, 0, 0],
 [0, 0, 0, 0, 0],
 [0, 0, 0, 1, 0]]

[[1, 1, 0, 1, 1],  # Day 1
 [1, 1, 1, 0, 1],
 [0, 1, 0, 1, 0],
 [0, 0, 1, 1, 1]]

[[1, 1, 1, 1, 1],  # Day 2
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [0, 1, 1, 1, 1]]

[[1, 1, 1, 1, 1],  # Day 3
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1]]

output = 3
```

```text
[[1, 0],  # Input
 [0, 0],
 [0, 0]]

[[1, 1],  # Day 1
 [1, 0],
 [0, 0]]

[[1, 1],  # Day 2
 [1, 1],
 [1, 0]]

[[1, 1],  # Day 3
 [1, 1],
 [1, 1]]

output = 3
```
