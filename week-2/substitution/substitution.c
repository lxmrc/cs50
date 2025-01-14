#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char rotate(char letter, char key[27]);
bool valid_key(char key[27]);

int main(int argc, char* argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26 || !valid_key(argv[1]))
    {
        printf("Invalid key.\n");
        return 1;
    }

    char key[27];
    strcpy(key, argv[1]);

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

char rotate(char letter, char key[27])
{
    if (!isalpha(letter))
    {
        return letter;
    }

    bool uppercase = isupper(letter);
    int index = (toupper(letter) - 'A');

    if (uppercase)
    {
        return toupper(key[index]);
    }
    else
    {
        return tolower(key[index]);
    }
}

bool valid_key(char key[27])
{
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; key[j]; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }

        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    return true;
}
