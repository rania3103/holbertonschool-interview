#!/usr/bin/python3
"""a function that returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid.
    (0 represents water,1 represents land)"""
    if not grid or not grid[0]:
        return 0
    n_rows = len(grid)
    n_cols = len(grid[0])
    p = 0
    for row in range(n_rows):
        for col in range(n_cols):
            if grid[row][col] == 1:
                p += 4
                if row > 0 and grid[row - 1][col] == 1:
                    p -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    p -= 2
    return p
