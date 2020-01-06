from sys import argv
import csv

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    else:
        with open(argv[1], newline='') as csvfile:
            db = csv.reader(csvfile, delimiter = ' ', quotechar = "|")
        print(db)


        s = open(argv[2], "r")
        seq = s.read()





if __name__ == "__main__":
    main()