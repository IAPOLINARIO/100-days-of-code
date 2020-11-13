## Coin Trouble

Given an array of coins, father needs to distribute them amongst his three children. Write a function to determine if the coins can be distributed equally or not. Return `true` if each son receives the same amount of money, otherwise return `false`.

```
[1, 2, 3, 2, 2, 2, 3] ➞ true
```

- Amount to be distributed to each child = `(1+2+3+2+4+3)/3 => 15/3 => 5`
- Possible set of coin to be distributed to children = `[(1,2,2),(2,3),(2,3)]`

```
[5, 3, 10, 1, 2] ➞ false
```

- Amount to be distributed to each child = `(5+3+10+1+2)/3 => 21/3 => 7`
- But there are no combination such that each child get equal value which is `7`.

### Example

```text
coinsDiv([1, 2, 3, 2, 2, 2, 3]) ➞ true

coinsDiv([5, 3, 10, 1, 2]) ➞ false

coinsDiv([2, 4, 3, 2, 4, 9, 7, 8, 6, 9]) ➞ true
```

### Notes

- Inputs will be an array of positive integers only.
- Coin can be any positive value.
