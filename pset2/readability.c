#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");

    // computing total letter count
    float lettercount = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        char l = text[i];
        if ((l >= 97 && l < 123) || (l >= 65 && l < 91))
        {
            lettercount++;
        }
    }

    // computing total word count
    float wordcount = 1;
    for (int j = 0; text[j] != '\0'; j++)
    {
        char w = text[j];
        if (isspace(w))
        {
            wordcount++;
        }
    }

    // computing total sentence count
    float sentencecount = 0;
    for (int k = 0; text[k] != '\0' ; k++)
    {
        char s = text[k];
        if (s == 33 || s == 46 || s == 63)
        {
            sentencecount++;
        }
    }

    // tabulating L and S values per 100 words
    float L = lettercount * (100 / wordcount);
    float S = sentencecount * (100 / wordcount);

    // Coleman-Liau index
    int index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}