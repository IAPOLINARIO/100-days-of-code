## Analog Clock

Write a program which displays the current system time as an analog clock, using ASCII graphics. The clock must show at least the hour and minute pointers, and must have enough resolution of at least 5 minutes.

The display can be as small and as ugly as you wish, but the shown time should be easily recognizable.

The program has to run continuously and update its status. If your system can clear the screen, use it, otherwise it's enough to repaint the clock when its state changes.

### Examples

```
+- 10:10 - - - - - - - + - 12:30 - - - - - - - + - 09:15 - - - - - - - +
|      . . 12. .       |       . . 12. .       |       . . 12. .       |
|    11          1     |     11    H     1     |     11          1     |
|  10              2   |   10      H       2   |   10              2   |
|.   H           M   . | .         H         . | .                   . |
|.   H H H   M M M   . | .         H         . | .                   . |
|9                   3 | 9                   3 | 9 H H H H   M M M M 3 |
|.                   . | .         M         . | .                   . |
|.                   . | .         M         . | .                   . |
|  8               4   |   8       M       4   |   8               4   |
|    7           5     |     7     M     5     |     7           5     |
|      . . 6 . .       |       . . 6 . .       |       . . 6 . .       |
+- - - - - - - - - - - + - - - - - - - - - - - + - - - - - - - - - - - +
+- 15:00 - - - - - - - + - 06:00 - - - - - - - + - 16:40 - - - - - - - +
|      . . 12. .       |       . . 12. .       |       . . 12. .       |
|    11    M     1     |     11    M     1     |     11          1     |
|  10      M       2   |   10      M       2   |   10              2   |
|.         M         . | .         M         . | .                   . |
|.         M         . | .         M         . | .                   . |
|9           H H H H 3 | 9                   3 | 9                   3 |
|.                   . | .         H         . | .   M M M   H H H   . |
|.                   . | .         H         . | .   M           H   . |
|  8               4   |   8       H       4   |   8               4   |
|    7           5     |     7     H     5     |     7           5     |
|      . . 6 . .       |       . . 6 . .       |       . . 6 . .       |
+- - - - - - - - - - - + - - - - - - - - - - - + - - - - - - - - - - - +
```
