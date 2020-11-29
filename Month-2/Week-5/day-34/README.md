# Primary Arithmetic

Children are taught to add multi-digit numbers from right to left, one digit at a time. 
Many find the “carry” operation, wherea 1 is carried from one digit position to the next, to be a significant challenge. 

Your job is to count the number of carry operations for each of a set of addition problems so that educators may assess their difficulty.

## Details

Write a **carryOperations** function.
The function has the following parameters:
- **num1**: first integer to sum
- **num2**: second integer to sum

Returns:
- Number of carry operations as an integer

## Constraints
- Input parameters are unsigned integers less than 10 digits.


### Example
```text
carryOperations(123, 456) ➞ 0
carryOperations(555, 555) ➞ 3
carryOperations(123, 594) ➞ 1
carryOperations(555, 545) ➞ 3
carryOperations(1, 20000) ➞ 0
carryOperations(1, 2) ➞ 0
```
