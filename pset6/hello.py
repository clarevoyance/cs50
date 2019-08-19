from cs50 import get_string

def main():

    # runs python version of hello.c
    name = get_string("What is your name?\n")
    print("hello, " + name)


__name__ = "__main__":
    main()