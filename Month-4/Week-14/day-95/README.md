## Free Cash

Valera runs a 24/7 fast food cafe. He magically learned that next day n people will visit his cafe. For each person we know the arrival time: the i-th person comes exactly at hi hours mi minutes. The cafe spends less than a minute to serve each client, but if a client comes in and sees that there is no free cash, than he doesn't want to wait and leaves the cafe immediately.

Valera is very greedy, so he wants to serve all n customers next day (and get more profit). However, for that he needs to ensure that at each moment of time the number of working cashes is no less than the number of clients in the cafe.

Help Valera count the minimum number of cashes to work at his cafe next day, so that they can serve all visitors.


### Input
The first line contains a single integer n (1 ≤ n ≤ 105), that is the number of cafe visitors.

Each of the following n lines has two space-separated integers hi and mi (0 ≤ hi ≤ 23; 0 ≤ mi ≤ 59), representing the time when the i-th person comes into the cafe.

Note that the time is given in the chronological order. All time is given within one 24-hour period.
```
4
8 0
8 10
8 10
8 45
```

### Output
Print a single integer — the minimum number of cashes, needed to serve all clients next day.
```
2
```

### Input
```
3
0 12
10 11
22 22
```

### Output
```
1
```


### Notes
In the first sample it is not enough one cash to serve all clients, because two visitors will come into cafe in 8:10. Therefore, if there will be one cash in cafe, then one customer will be served by it, and another one will not wait and will go away.

In the second sample all visitors will come in different times, so it will be enough one cash.