## Dreamoon and Stairs

Dreamoon wants to climb up a stair of **n** steps. He can climb 1 or 2 steps at each move. Dreamoon wants the number of moves to be a multiple of an integer **m**.

What is the minimal number of moves making him climb to the top of the stairs that satisfies his condition?

### Input
The single line contains two space separated integers **n**, **m** (0 < n ≤ 10000, 1 < m ≤ 10).
```
10 2
```

### Output
Print a single integer — the minimal number of moves being a multiple of **m**. If there is no way he can climb satisfying condition print  **-1** instead.
```
6
```

### Input
```
3 5
```

### Output
```
-1
```

### Note
For the first sample, Dreamoon could climb in 6 moves with following sequence of steps: {2, 2, 2, 2, 1, 1}.

For the second sample, there are only three valid sequence of steps {2, 1}, {1, 2}, {1, 1, 1} with 2, 2, and 3 steps respectively. All these numbers are not multiples of 5.

### More examples of Input & Output
```    
    climbMoves(13, 2) == 8 //2 2 2 2 2 1 1 1    
    climbMoves(6, 4) == 4 //2 2 1 1
    climbMoves(7, 4) == 4 //2 2 2 1 
    climbMoves(8, 4) == 4 //2 2 2 2 
    climbMoves(9, 4) == 8 //2 1 1 1 1 1 1 1
    climbMoves(5, 3) == 3 //2 2 1
    climbMoves(6, 3) == 3 //2 2 2
    climbMoves(7, 3) == 6 //2 1 1 1 1 1
```