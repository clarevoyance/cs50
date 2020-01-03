#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text:")

    int lettercount = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (i != char " ")
        {
            lettercount += 1;
        }
        else
        {
            lettercount += 0;
        }
        
    }

    printf("%s\n", text)
}