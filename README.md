# Mancala with rudimentary "AI"s


The board is simply a vector of integers representing the marbles in a slot. When a Board is constructed it is filled with a 0, six 4’s, another 0, and six more 4’s. Looks something like this:
```
---------------------------------
|   | 4 | 4 | 4 | 4 | 4 | 4 |   |
| 0 |		            | 0 |
|   | 4 | 4 | 4 | 4 | 4 | 4 |   |
---------------------------------
```
With indexes like this:
```
---------------------------------
|   | 6 | 5 | 4 | 3 | 2 | 1 |   |
| 7 |		            | 0 |
|   | 8 | 9 | 10| 11| 12| 13|   |
---------------------------------
```
I made my AggressiveAgent. Its goal is simply to get as many points as it can in a turn, otherwise move randomly. It checks first to see if it can get a free move. If it can get a free move, it takes it. Otherwise it runs through all of its potential moves to find which gives it the best return.
	
Next I made the DefensiveAgent. Its strategy is to give up the least points. Its turn starts by making a move, then checking the enemy’s best move based on its move. it does this for all of its potential moves. it also takes the free turn if it can.

Lastly there is the BiPolarAgent. This final agent takes in a number between 1 and 100. This number determines the percent of the time it makes an aggressive type move. Otherwise it makes a defensive move.

MonPolarMancala.cpp is currently set up to have 2 Aggressive agents play each other, but adjust the commented out agents to see how others deal.
