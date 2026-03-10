#!/usr/bin/python3
"""
Module containing the canUnlockAll function.

This module solves the lockboxes problem where we need to determine
if all boxes can be opened starting from box 0.
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened.

    Args:
        boxes (list): List of lists where each sublist contains keys
                     to other boxes. Box 0 is unlocked by default.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    if n == 0:
        return True

    opened = set([0])

    to_explore = [0]

    while to_explore:
        current_box = to_explore.pop()

        for key in boxes[current_box]:

            if isinstance(key, int) and 0 <= key < n and key not in opened:
                opened.add(key)
                to_explore.append(key)

    return len(opened) == n
