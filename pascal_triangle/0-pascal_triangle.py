#!/usr/bin/python3
"""a function that returns a list of lists of integers
representing the Pascal’s triangle of n"""


def pascal_triangle(n):
    """Returns an empty list if n <= 0"""
    if n <= 0:
        return []
    pascal_triangle = [[1]]
    for row in range(1, n):
        pascal_triangle.append([0] * (row + 1))
        pascal_triangle[row][0] = 1
        pascal_triangle[row][row] = 1
        for col in range(1, row):
            pascal_triangle[row][col] = pascal_triangle[row - 1][col - 1] + \
                pascal_triangle[row - 1][col]
    return pascal_triangle
