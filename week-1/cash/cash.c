#include <stdio.h>
#include <string.h>

int main(void) {
    int change_owed;
    while (1) {
        printf("Change owed: ");
        if (scanf("%d", &change_owed) == 1 && change_owed >= 0) {
            break;
        }
        while (getchar() != '\n')
            ;
    }

    int coins = 0;

    while (change_owed > 0) {
        if (change_owed >= 25) {
            int quarters = (int)change_owed / 25;
            coins += quarters;
            change_owed -= quarters * 25;
        } else if (change_owed >= 10) {
            int dimes = (int)change_owed / 10;
            coins += dimes;
            change_owed -= dimes * 10;
        } else if (change_owed >= 5) {
            int nickels = (int)change_owed / 5;
            coins += nickels;
            change_owed -= nickels * 5;
        } else {
            coins += change_owed;
            change_owed = 0;
        }
    }

    printf("%i\n", coins);
}
