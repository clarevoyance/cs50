from sys import argv
from cs50 import get_string, islower, isupper

def main():

    if len(sys.argv) != 2:
        print("Provide command line arguments!")

    if k < 0 :
        print("Provide provide a value larger than 0!")

    else:
        code = get_string("plaintext: ")
        print("ciphertext: ")

        for i in range(len(code)):

            k = atoi

            if islower(code[i]):
                print((((code[i] + k) - 97) % 26) + 97)) 
            else:
                print((((code[i] + k) - 97) % 26) + 97))


if __name__ == "__main__":
    main()