#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """returns the minimum number of operations"""
    if n <= 1:
        return 0
    else:
        div = 2
        sum_prime_fact = 0
        while (n > 1):
            if n % div == 0:
                n = n // div
                sum_prime_fact += div
            else:
                div += 1
        return sum_prime_fact
