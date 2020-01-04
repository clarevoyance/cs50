from sys import argv
import csv

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    else:
        file open(argv[1], "r")


if __name__ == "__main__":
    main()