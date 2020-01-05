#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctyp e.h>

int main(void)
{
    string text = get_string("Text: ");

    // computing total letter count
    float lettercount = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char l = text[i];
        if ((l >= 97 && l < 123) || (l >= 65 && l < 91))
        {
            lettercount += 1;

        }
    }
    //printf("%f letter(s)\n", lettercount);

    // computing total word count
    float wordcount = 1;
    for (int j = 0, n = strlen(text); j < n; j++)
    {
        char w = text[j];
        if (isspace(w))
        {
            wordcount += 1;
        }
    }
    //printf("%f word(s)\n", wordcount);

    // computing total sentence count
    float sentencecount = 0;
    for (int k = 0, n = strlen(text); k < n; k++)
    {
        char s = text[k];
        if (s == 33 || s == 46 || s == 63)
        {
            sentencecount += 1;
        }
    }
    //printf("%f sentence(s)\n", sentencecount);

    // tabulating L and S values per 100 words
    float L = lettercount * (100 / wordcount);
    //printf("L is %f\n", L);
    float S = sentencecount * (100 / wordcount);
    //printf("S is %f\n", S);

    // Coleman-Liau index
    int index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("Coleman-Liau index: %i\n", index);

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