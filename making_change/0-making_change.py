#!/usr/bin/env python3
"""Given a pile of coins of different values,
determine the fewest number of coins needed to
meet a given amount total"""


def makeChange(coins, total):
    """Return: fewest number of coins needed to meet total"""
    if total <= 0:
        return 0
    li = [total + 1] * (total + 1)
    li[0] = 0
    for coin in coins:
        for amount in range(coin, total + 1):
            li[amount] = min(li[amount], li[amount - coin] + 1)
    if li[total] != total + 1:
        return li[total]
    else:
        return -1
