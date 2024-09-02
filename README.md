# game-of-life

# Project Description:

This is an implementation of the 'Game of Life' by John Conway. The main rules to it are:
1. If a cell is “alive” in the current generation, then depending on its neighbor’s state, in the next generation the cell will either live or die based on the following conditions:
   - Each cell with one or no neighbor dies, as if by loneliness.
   - Each cell with four or more neighbors dies, as if by overpopulation.
   - Each cell with two or three neighbors survives.

2. If a cell is “dead” in the current generation, then if there are exactly three neighbors "alive," it will change to the "alive" state in the next generation, as if the neighboring cells gave birth to a new organism.

# To Compile and Run

```bash
    gcc main.c game_of_life.c
    ./a matrix_size number_of_generations
    