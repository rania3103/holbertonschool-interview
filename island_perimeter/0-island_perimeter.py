#!/usr/bin/python3
"""a function that returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """0 represents water and 1 represents land"""
    n_rows = len(grid)
    n_cols = len(grid[0])
    p = 0
    for row in range(n_rows):
        for col in range(n_cols):
            if grid[row][col] == 1:
                # top
                if row == 0 or grid[row - 1][col] == 0:
                    p += 1
                # bottom
                if row == n_rows - 1 or grid[row + 1][col] == 0:
                    p += 1
                # left
                if col == 0 or grid[row][col - 1] == 0:
                    p += 1
                # right
                if col == n_cols - 1 or grid[row][col + 1] == 0:
                    p += 1
    return p