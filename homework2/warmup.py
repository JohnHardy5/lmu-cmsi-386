"""Homework assignment 2 written by John Hardy and Jordan Sanders."""

import random
from Crypto.Cipher import AES
import requests


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


def strip_quotes(s):
    """Remove apostrophes and double quotes from a given string."""
    s = s.replace("'", "")
    return s.replace('"', '')


def scramble(string):
    """Randomly permute a given string."""
    result = list(string)
    for x in range(len(result)):
        random_element = random.randrange(len(string))
        result[x], result[random_element] = result[random_element], result[x]
    return "".join(result)


def powers(base, limit):
    """Yield succesive powers of a base from one to a specific limit."""
    
    count, future = 0, 0
    while future <= limit:
        current = base ** count
        yield current
        future = base ** (count + 1)
        count += 1

def triples(limit):
    """Return a list of all pythagorean triples up to and including a limit."""
    return [(a, b, c)
            for a in range(1, (limit + 1))
            for b in range(1, (limit + 1))
            for c in range(1, (limit + 1))
            if a**2 + b**2 == c**2 and a < b and b < c]


def say(start_word=None):
    """Chainable function that returns a word based on chained arguments."""
    result = []

    def say_again(word=None):
        if word is None:
            return " ".join(result)
        result.append(word)
        return say_again
    return say_again(start_word)


def interleave(*arguments):
    """Interleave first argument array with remaining arguments."""
    first_array = arguments[0]
    largest = max(len(first_array), len(arguments) - 1)
    result = []
    for i in range(largest):
        if i < len(first_array):
            result.append(first_array[i])
        if i < len(arguments) - 1:
            result.append(arguments[i + 1])
    return result


class Cylinder:
    """Create a Python class for a Cylinder."""
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height

    def surface_area(self):
        return 2 * math.pi * self.radius * (self.height + self.radius)

    def volume(self):
        return math.pi * self.radius ** 2 * self.height

    def widen(self, widenfactor):
        self.radius *= widenfactor

    def stretch(self, stretchfactor):
        self.height *= stretchfactor


def make_crypto_functions(key, vector):
    """Use an AES algorithmn to encrypt or decrypt a vector given a key."""
    new_key, new_vector = bytes(key, "utf-8"), bytes(vector, "utf-8")

    def encrypt(to_encrypt):
        encryption_suite = AES.new(new_key, AES.MODE_CBC, new_vector)
        return encryption_suite.encrypt(to_encrypt)

    def decrypt(to_decrypt):
        decryption_suite = AES.new(new_key, AES.MODE_CBC, new_vector)
        return decryption_suite.decrypt(to_decrypt)
    return (encrypt, decrypt)


def random_name(gender, region):
    """Return a random name from the uinames API."""
    pay_load = {"gender": gender, "region": region, "amount": 1}
    r = requests.get("http://uinames.com/api/", params=pay_load)
    response = r.text
    if response == '{"error":"Invalid gender"}':
        raise ValueError(response)
    surname = ""
    for i in range(response.find('rname":"') + 8, response.find('","g')):
        surname += response[i]
    name = ""
    for i in range(response.find('"name":"') + 8, response.find('","s')):
        name += response[i]
    return surname + ", " + name
