#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Map of points per letter
const int letter_values[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Calculate how many points a word is worth
int calculateScore(char word[16], int *player)
{
    for (int i = 0; i < strlen(word); i++)
    {
        char letter = toupper(word[i]);
        *player += letter_values[letter - 'A'];
    }
    return *player;
}

int main(void)
{
    // Accept input for player 1
    char word_1[16];
    printf("Player 1: ");
    scanf("%s", word_1);

    // Accept input for player 2
    char word_2[16];
    printf("Player 2: ");
    scanf("%s", word_2);

    // Calculate player 1's score
    int player_1_score = 0;
    calculateScore(word_1, &player_1_score);

    // Calculate player 2's score
    int player_2_score = 0;
    calculateScore(word_2, &player_2_score);

    // Determine the outcome
    if (player_1_score > player_2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_2_score > player_1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
