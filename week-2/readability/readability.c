#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[1000];
    printf("Text: ");
    fgets(text, 1000, stdin);

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        if (isalpha(letter))
        {
            letters++;
        }
        else if ((letter == ' ') || (letters > 0 && text[i + 1] == '\0'))
        {
            words++;
        }
        else if ((letter == '.') || (letter == '?') || (letter == '!'))
        {
            sentences++;
        }
    }

    double L = (letters * 100.0) / words;
    double S = (sentences * 100.0) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // printf("Letters: %d\n", letters);
    // printf("Words: %d\n", words);
    // printf("Sentences: %d\n", sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
