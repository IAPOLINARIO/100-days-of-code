# Asteroid Collision

You are given an array **asteroids** of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the **asteroids** after all collisions. If two **asteroids** meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

## Examples
```text
asteroidCollision([-2, -1, 1, 2]) ➞ [-2, -1, 1, 2]

asteroidCollision([-2, 1, 1, -2]) ➞ [-2, -2]

asteroidCollision([1, 1, -2, -2]) ➞ [-2, -2]

asteroidCollision([10, 2, -5]) ➞ [10]

asteroidCollision([8, -8]) ➞ []
```