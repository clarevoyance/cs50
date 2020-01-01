from cs50 import get_string

def main():

    text = get_string("Text: ")

    lettercount = 0
    for i in text:
        if i is not " ":
            lettercount += 1
        else:
            lettercount += 0
    print(lettercount, "letter(s)")


if __name__ == "__main__":
    main() 