# Halloween Sale

You wish to buy video games from the famous online video game store Mist.

Usually, all games are sold at the same price,*p* dollars. However, they are planning to have the seasonal Halloween Sale next month in which you can buy games at a cheaper price. Specifically, the first game you buy during the sale will be sold at *p* dollars, but every subsequent game you buy will be sold at exactly *d* dollars less than the cost of the previous one you bought. This will continue until the cost becomes less than or equal to *m* dollars, after which every game you buy will cost *m* dollars each.

You have *s* dollars in your Mist wallet. How many games can you buy during the Halloween Sale?

## Objective
Create a **howManyGames** function, it has the following parameter(s):
- int p Normal price of games
- int d The discount
- int m Minimium vale per game
- int s The budget

Returns
- int: the number of games you can buy

## Example
```text
howManyGames(20, 3, 6, 80) ➞ 6
```