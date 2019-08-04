#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, string argv[])
{

    // ensure only 1 keyword
    if (argc != 2) 
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }    
    int m = strlen(argv[1]);
    
    // check that argument contains only alphabetic string
    for (int i = 0; i < m; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }

    // prompt user for a code to encrypt
    string code = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = 0, result = 0, n = strlen(code); i < n; i++)
    {
        char letter = code[i];
        // put key into char key
        char key = argv[1][(j) % m];

        if (isupper(letter))
        {
            key -= 65;
        }
        else if (islower(letter))
        {
            key -= 97;
        }
        
        // check if the letter is uppercase or lowercase before converting
        if (islower(letter))
        {
            printf("%c", (letter + key - 97) % 26 + 97);
            j++;
        }
        else if (isupper(letter))
        {
            printf("%c", (letter + key - 65) % 26 + 65);
            j++;
        }
        // if neither just print plaintext
        else
        {
            result = letter;
            printf("%c", result);
        } 
    }
    printf("\n");
    return 0;
}
