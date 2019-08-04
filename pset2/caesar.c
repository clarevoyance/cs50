#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, string argv[])
{
    // ensure only 1 keyword
    if (argc != 2) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // check if the integer is non-negative
    if (k < 0) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } 
    else 
    {
        // prompt user for a code to encrypt
        string code = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(code); i < n; i++) 
        {

            // once I check for correct argv put key into an int k
            int k = atoi(argv[1]);            
            // check if the letter is uppercase or lowercase before converting
            if islower(code[i])
            {
                printf("%c", (((code[i] + k) - 97) % 26) + 97);
            }        
            else if isupper(code[i])
            {
                printf("%c", (((code[i] + k) - 65) % 26) + 65);
            }        
            // if neither then just print plaintext
            else
            {
                printf("%c", code[i]);
            }
        }
        printf("\n");
        return 0;
    }
}