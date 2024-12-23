#!/usr/bin/python3
"""Maria and Ben are playing a game. Given a set of consecutive integers
starting from 1 up to and including n, they take turns choosing a prime
number from the set and removing that number and its multiples from the set.
The player that cannot make a move loses the game.
They play x rounds of the game, where n may be different for each round.
Assuming Maria always goes first and both players play optimally,
determine who the winner of each game is."""


def is_prime(num):
    """check if a number is prime"""
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def isWinner(x, nums):
    """Return: name of the player that won the most rounds
    If the winner cannot be determined, return None"""
    if not nums or x < 1:
        return None
    maria_wins = 0
    ben_wins = 0
    for n in nums:
        primes = [i for i in range(1, n + 1) if is_prime(i)]
        turn = 0
        while primes:
            prime = primes[0]
            primes = [num for num in primes if num % prime != 0]
            turn = 1 - turn
        if turn == 1:
            maria_wins += 1
        else:
            ben_wins += 1
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
