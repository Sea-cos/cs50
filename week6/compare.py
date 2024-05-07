from cs50 import get_int

x = get_int("X: ")
y = get_int("Y: ")

if x < y:
    print("X is less")
elif x > y:
    print("X is greater")
else:
    print("X is equal")
