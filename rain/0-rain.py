#!/usr/bin/python3
"""calculate how many square units of water will be retained after it rains."""


def rain(walls):
    """Return: Integer indicating total amount of rainwater retained."""
    if not walls:
        return 0
    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    total_water = 0
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])
    for i in range(n):
        water_at_pos_i = min(left_max[i], right_max[i]) - walls[i]
        if water_at_pos_i > 0:
            total_water += water_at_pos_i
    return total_water
