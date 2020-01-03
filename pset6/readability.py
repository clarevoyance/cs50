from cs50 import get_string


def main():

    text = get_string("Text: ")

    lettercount = 0
    for i in text:
        if i is not (" " or "." or "?" or "!"):
            lettercount += 1
        else:
            lettercount += 0

    wordcount = 0
    for j in text.split():
        wordcount += 1

    sentencecount = 0
    for k in text:
        if k is "." or k is "!" or k is "?":
            sentencecount += 1
        else:
            sentencecount += 0
    if sentencecount == 0:
        sentencecount += 1

    L = lettercount * (100 / wordcount)
    S = sentencecount * (100 / wordcount)
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = int(index)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade", grade)


if __name__ == "__main__":
    main()