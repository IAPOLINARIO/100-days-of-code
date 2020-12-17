# Electronics Shop

A person wants to determine the most expensive computer keyboard and USB drive that can be purchased with a give budget. Given price lists for keyboards and USB drives and a budget, find the cost to buy them. If it is not possible to buy both items, return -1.

## Objective
Create a **getMoneySpent** function, it has the following parameter(s):
- int keyboards[]: the keyboard prices 
- int drives[]: the drive prices 
- int b: the budget 

Returns
- int: the maximum that can be spent, or -1 if it is not possible to buy both items.

## Example
```text
getMoneySpent([40,50,60],[5,8,12],60) ➞ 58
```

In the example above, the person can buy a *40 keyboard + 12 USB drive = 52* or a *50 keyboard + 8 USB drive = 58*. Choose the latter as the more expensive option and return *58*.