from cs50 import get_int

# prompt for height where h is an integer between 1 and 8
while True:
    h = get_int("Height: ")
    w = h
    if h > 0 and h <= 8:
        break

# print # based on input value of h
for i in range(1, h + 1):
    hash = i
    spaces = w - hash

    print(" " * spaces, end="")
    print("#" * hash)