"""Homework assignment 2 written by John Hardy and Jordan Sanders."""

import random


def change(cents_left):
    """Calculate change in US currency given a number of cents."""
    if cents_left < 0:
        raise ValueError("amount cannot be negative")
    denominations = [25, 10, 5, 1]
    for d in range(len(denominations)):
        current_denomination = denominations[d]
        denominations[d] = cents_left // current_denomination
        cents_left %= current_denomination
    return tuple(denominations)


def strip_quotes():
    """Remove apostrophes and double quotes from a given string."""
    pass


def scramble(string):
    """Randomly permute a given string."""
    if string == "":
        return ""
    random_element = random.randrange(0, len(string))
    random_char = string[random_element]
    string = string[:random_element] + string[random_element + 1:]
    string = random_char + scramble(string)
    return string


def powers():
    """Yield succesive powers of a base from one to a specific limit."""
    pass


def triples(limit):
    """Return a list of all pythagorean triples up to and including a limit."""
    result = []
    for a in range(1, (limit + 1)):
        for b in range(1, (limit + 1)):
            for c in range(1, (limit + 1)):
                if a ** (2) + b ** (2) == c ** (2):
                    result.insert(0, (a, b, c))
                    print("Current list: " + str(result))
                    if len(result) > 1:
                        print("Comparison of first two: " + str(result[0] == result[1]))
    return result


def say():
    """Chainable function that returns a word based on chained arguments."""
    pass


def interleave():
    """Interleave first argument array with remaining arguments."""
    pass


def Cylinder():
    """Create a Python class for a Cylinder."""
    pass


def make_crypto_functions():
    """Use an AES algorithmn to encrypt or decrypt a vector given a key."""
    pass


def random_name():
    """Return a random name from the uinames API."""
    pass
