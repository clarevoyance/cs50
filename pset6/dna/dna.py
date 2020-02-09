from sys import argv
import csv

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    else:

        # Read csv file into dictionary
        dbfile = open(argv[1], "r")
        dbread = dbfile.readlines()
        dbdict = {}
        dblist = []
        
        for item in dbread:
            entry = item.split(",")
            entry[-1] = entry[-1].strip("\n")
            dblist.append(entry)

        for item in dblist[1:]:
            dbvalues = {}
            for i in range(1, len(item)):
                dbvalues[dblist[0][i]] = item[i]
            dbdict[item[0]] = dbvalues

        dbfile.close()


        # Read sequence into list
        seqfile = open(argv[2], "r")
        seqlist = []

        seq = seqfile.readlines()
        seqstr = ""
        for i in seq:
            seqstr += i
            
        for i in seqstr:
            seqlist.append(i)

        seqfile.close()

        # Tabulating counts
        
            
if __name__ == "__main__":
    main()