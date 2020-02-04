#!/usr/local/bin/python3

from random import randint

f = open('nums.dat', 'w')

for i in range(0, 1000):
    r = randint(0, 999999999)

    if not r % 2 == 0:
        f.write(f"{r}\n")
        print(r)
