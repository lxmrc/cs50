// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string str);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
}

string replace(string str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'a')
        {
            str[i] = '6';
        }
        else if (str[i] == 'e')
        {
            str[i] = '3';
        }
        else if (str[i] == 'i')
        {
            str[i] = '1';
        }
        else if (str[i] == 'o')
        {
            str[i] = '0';
        }
        else
        {
            str[i] = str[i];
        }
    }

    return str;
}
