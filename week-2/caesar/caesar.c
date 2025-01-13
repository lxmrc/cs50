#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string str);
char rotate(char letter, int key);

int main(int argc, char* argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    char ciphertext[length + 1];

    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
    }

    ciphertext[length] = '\0';

    printf("ciphertext: %s\n", ciphertext);
}

bool only_digits(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }

    return true;
}

char rotate(char letter, int key)
{
    if (!isalpha(letter))
    {
        return letter;
    }
    else
    {
        if (islower(letter))
        {
            return ((letter - 'a') + key) % 26 + 'a';
        }
        else if (isupper(letter))
        {
            return ((letter - 'A') + key) % 26 + 'A';
        }
    }
}
