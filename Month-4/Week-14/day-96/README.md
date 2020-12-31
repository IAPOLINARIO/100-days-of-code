## Beautiful Paintings

There are **n** pictures delivered for the new exhibition. The i-th painting has beauty ai. We know that a visitor becomes happy every time he passes from a painting to a more beautiful one.

We are allowed to arranged pictures in any order. What is the maximum possible number of times the visitor may become happy while passing all pictures from first to last? In other words, we are allowed to rearrange elements of a in any order. What is the maximum possible number of indices i (1 ≤ i ≤ n - 1), such that ai + 1 > ai.

### Input
The first line of the input contains integer n (1 ≤ n ≤ 1000) — the number of painting.

The second line contains the sequence a1, a2, ..., an (1 ≤ ai ≤ 1000), where ai means the beauty of the i-th painting.
```
5
20 30 10 50 40
```

### Output
Print one integer — the maximum possible number of neighbouring pairs, such that ai + 1 > ai, after the optimal rearrangement.
```
4
```

### Input
```
4
200 100 100 200
```

### Output
```
2
```


### Notes
In the first sample, the optimal order is: 10, 20, 30, 40, 50.

In the second sample, the optimal order is: 100, 200, 100, 200.