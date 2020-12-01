# Climbing the Leaderboard

An arcade game player wants to climb to the top of the leaderboard and track their ranking. 

The game uses [Dense Ranking][1], so its leaderboard works like this:
- The player with the highest score is ranked number 1 on the leaderboard.
- Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.


Create a function with the following input parameters, in this order:
- **rankedScores**: leaderboard scores as an integer list
- **playerScores**: the scores of the games of the player as an integer list

Returns:
- The player's rank after each new score, as an integer list

### Example
```text
playerRank([100, 90, 90, 80], [70, 80, 105])  ➞ [4, 3, 1]
```

In the above example, ranked players will have ranks **1**, **2**, **2**, and **3**, respectively. If the player's scores are **70**, **80** and **105**, their rankings after each game are **4***th*, **3***th* and **1***th*. Return **[4, 3, 1]**.

### Additional Example
```text
playerRank([100, 90, 90, 80], [106, 107, 105])  ➞ [1, 1, 1]
```

[1]: https://en.wikipedia.org/wiki/Ranking#Dense_ranking_(%221223%22_ranking)