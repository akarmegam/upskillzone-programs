# Egg Dropping Puzzle - n eggs and m floors

Detailed information about this puzzle and solution with pseudocode is present
in [upskillzone.com](https://upskillzone.com/Interview-Puzzles/Egg-Dropping-Puzzle-n-eggs-and-m-floors.html)
site. Here the puzzle implementation in C program is archived.

## 1. Building
- To build
```
make
```

## 2. Execute
- The `egg-dropping-puzzle` exe takes 3 argument as input.
  - `--eggs`: Number of available eggs.
  - `--floors`: Number of floors.
  - `--safe-floor`: How many floors from ground are safe for eggs. Safe means
  egg wont break.
- To run the program for **10 floors and 2 eggs** with the safest floor 4.

```
./egg-dropping-puzzle --eggs 2 --floors 10 --safe-floor 4
```
- And the output will be
```
2 eggs and 10 floors
Check among floors between 1 and 10 with 2 eggs
 - Doing binary traversal
 - Checking floor 5
 - 5 is unsafe floor
Check among floors between 1 and 4 with 1 eggs
 - Doing linear traversal
 - Checking floor 1
 - 1 is safe floor
Check among floors between 2 and 4 with 1 eggs
 - Doing linear traversal
 - Checking floor 2
 - 2 is safe floor
Check among floors between 3 and 4 with 1 eggs
 - Doing linear traversal
 - Checking floor 3
 - 3 is safe floor
Check among floors between 4 and 4 with 1 eggs
 - Doing linear traversal
 - Checking floor 4
 - 4 is safe floor
It took 5 checks to find safest floor 4 out of 10 floors with 2 eggs
```
