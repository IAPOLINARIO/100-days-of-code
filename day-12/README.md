## Mountains or Valleys

A mountain is an array with **exactly one peak.**

- All numbers to the left of the **peak** are increasing.
- All numbers to the right of the **peak** are decreasing.
- The peak CANNOT be on the boundary.

A valley is an array with **exactly one trough**.

- All numbers to the left of the **trough** are decreasing.
- All numbers to the right of the **trough** are increasing.
- The trough CANNOT be on the boundary.

### Some examples of **mountains** and **valleys**:

```text
Mountain A:  [1, 3, 5, 4, 3, 2]   // 5 is the peak
Mountain B:  [-1, 0, -1]   // 0 is the peak
Mountain B:  [-1, -1, 0, -1, -1]   // 0 is the peak (plateau on both sides is okay)

Valley A: [10, 9, 8, 7, 2, 3, 4, 5]   // 2 is the trough
Valley B: [350, 100, 200, 400, 700]  // 100 is the trough
```

Neither **mountains** nor **valleys**:

```text
Landscape A: [1, 2, 3, 2, 4, 1]  // 2 peaks (3, 4), not 1
Landscape B: [5, 4, 3, 2, 1]  // Peak cannot be a boundary element
Landscape B: [0, -1, -1, 0, -1, -1]  // 2 peaks (0)
```

Based on the rules above, write a function that takes in an array and returns either `"mountain"`, `"valley"`, or `"neither"`.

### Examples

```text
LandscapeType([3, 4, 5, 4, 3]) ➞ "mountain"

LandscapeType([9, 7, 3, 1, 2, 4]) ➞ "valley"

LandscapeType([9, 8, 9]) ➞ "valley"

LandscapeType([9, 8, 9, 8]) ➞ "neither"
```

---

### Notes

- A peak is not exactly the same as the **max** of an array. The **max** is a unique number, but an array may have multiple peaks. However, if there exists only one peak in an array, then it is true that the peak = max.
- See comments for a hint.
