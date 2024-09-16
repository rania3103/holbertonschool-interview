#!/usr/bin/python3
"""a script that reads stdin line by line and computes metrics"""
import sys
status_code = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
numb_lines = 0
tot_size = 0


def print_statistics():
    """a function that prints statistics of the log"""
    print(f'File size: {tot_size}')
    for code in sorted(status_code.keys()):
        if status_code[code] > 0:
            print(f'{code}: {status_code[code]}')


try:
    for line in sys.stdin:
        try:
            words = line.split()
            if len(words) == 6:
                file_size = int(words[5])
                code = int(words[4])
                if code in status_code.keys():
                    status_code[code] += 1
                    tot_size += file_size
                numb_lines += 1
                if numb_lines % 10 == 0:
                    print_statistics()
        except ValueError:
            continue

except KeyboardInterrupt:
    print_statistics()
