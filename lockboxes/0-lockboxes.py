#!/usr/bin/python3
"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """A key with the same number as a box opens that box
    Return True if all boxes can be opened, else return False
    """
    keys = [0]
    visited_boxes = set()
    can_open = True
    while keys:
        key = keys.pop()
        visited_boxes.add(key)
        for new in boxes[key]:
            if new not in visited_boxes and new < len(boxes):
                keys.append(new)
    if len(visited_boxes) != len(boxes):
        can_open = False
    return can_open
