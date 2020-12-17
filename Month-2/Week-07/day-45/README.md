# Subtract the swapped bits without temp storage

This is more informational than a challenge. You can actually switch 2 variables with the XOR operation ^. XOR works with two arguments. It turns both arguments in their binary representation, and for each bit, returns 1 if they are different, 0 otherwise.

Create a function to swap int variables *X* and *Y* _without the use of an additional temporary storage variable_ using _only_ [*XOR bitwise operations*][1].

## Output
- Return the *SUBTRACTION of swapped numbers* by [*XOR bitwise operations*][1].

_Example_

```text
XOR(10, 41) ➞ 31
XOR(69, 420) ➞ 351
XOR(12345, 890412) ➞ 878067
XOR(2, 1) ➞ -1
```

## Notes
- The swap operation needs to be done _without the use of an additional temporary storage variable_, using _only_ [*XOR bitwise operations*][1].  

## Constraints
- The input numbers *X* and *Y* are positive integers.
- The input numbers *X* and *Y* are different from each other.

[1]: https://en.wikipedia.org/wiki/Bitwise_operation#XOR