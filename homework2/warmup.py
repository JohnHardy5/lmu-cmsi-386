"""Homework assignment 1 written by John Hardy and Jordan Sanders."""


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


def scramble():
    """Randomly permute a given string."""
    pass


def powers():
    """Yield succesive powers of a base from one to a specific limit."""
    pass


def triples():
    """Return a list of all pythagorean triples up to and including a limit."""
    pass


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
