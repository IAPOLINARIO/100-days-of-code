# Climbing the Leaderboard

An arcade game player wants to climb to the top of the leaderboard and track their ranking. The game uses Dense Ranking, so its leaderboard works like this:
- The player with the highest score is ranked number 1 on the leaderboard.
- Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.


Create a function with the following input parameters, in this order:
- **n**: number of players on the leaderboard as an integer
- **ranked**: leaderboard scores in **decreasing order** as an integer array
- **m**: number of games the player plays as an integer
- **player**: the scores of the games of the player as an integer array

Returns:
- The player's rank after each new score, as an integer array

**Additional input validations**
- If **n** doesn't match the size of the ranked array, return an empty array as result.
- If **m** doesn't match the size of the player array, return an empty array as result.
- If the leaderboard **ranked** is not in **descending** order, return an empty array as result.
- If the **player**'s score is not in **ascending** order, return an empty array as result.

### Example
```text
playerRank(4, [100, 90, 90, 80], 3, [70, 80, 105])  ➞ [4, 3, 1]
```

In the above example, ranked players will have ranks **1**, **2**, **2**, and **3**, respectively. If the player's scores are **70**, **80** and **105**, their rankings after each game are **4***th*, **3***th* and **1***th*. Return **[4, 3, 1]**.

### Additional examples
```text
playerRank(3, [100, 90, 90, 80], 3, [70, 80, 105])  ➞ [] (invalid n)
playerRank(4, [100, 90, 90, 80], 4, [70, 80, 105])  ➞ [] (invalid m)
playerRank(4, [100, 90, 90, 91], 4, [70, 80, 105])  ➞ [] (leaderboard scores not in decreasing order)
playerRank(3, [100, 90, 90, 80], 3, [70, 106, 105])  ➞ [] (player's score not in ascending order)
```