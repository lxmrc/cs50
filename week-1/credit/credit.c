#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Accept input
    char card_number[17];
    printf("Number: ");
    scanf("%s", card_number);

    // Reverse to make looping easier
    int length = strlen(card_number);
    char rev[17];

    for (int i = 0; i < length; i++) {
        rev[i] = card_number[length - 1 - i];
    }

    rev[length] = '\0';

    // Luhn's algorithm
    int sum = 0;

    for(int i = 0; i < length; i++) {
        int digit = rev[i] - '0';

        if (i % 2 != 0) {
            int result = digit * 2;
            if (result < 10) {
                sum += result;
            } else {
                sum += result / 10;
                sum += result % 10;
            }
        } else {
            sum += digit;
        }
    }

    if(sum % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }

    // Determine which card provider
    char first_two_digits[3];
    strncpy(first_two_digits, card_number, 2);
    first_two_digits[2] = '\0';
    int first_two_digits_int = atoi(first_two_digits);

    if ((first_two_digits_int == 34 || first_two_digits_int == 37) && (length == 15)) {
        printf("AMEX\n");
        return 0;
    } else if ((first_two_digits_int >= 51 && first_two_digits_int <= 55) && (length == 16)) {
        printf("MASTERCARD\n");
        return 0;
    } else if((card_number[0] - '0' == 4) && (length == 13 || length == 16)) {
        printf("VISA\n");
        return 0;
    } else {
        printf("INVALID\n");
        return 0;
    }
}
