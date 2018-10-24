#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 3

int max(const int a, const int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int getNumber(void) {
    int number = 0;

    printf("%s", "Enter positive integer number: ");
    scanf("%d", &number);

    while (number < 0) {
        puts("You have entered incorrect number. Try again.");

        printf("%s", "Enter positive integer number: ");
        scanf("%d", &number);
    }

    return number;
}

void printLargestNumbers(const int a, const int b) {
    if (a > b) {
        printf(
            "First largest number is: %d\n"
            "Second largest number is: %d\n",
            a, b);
    } else {
        printf(
            "First largest number is: %d\n"
            "Second largest number is: %d\n",
            b, a);
    }
}

int main() {
    int number = 0;
    int maxValue = 0;
    int prevToMaxValue = 0;

    if (MAX_NUMBERS > 0) {
        if (MAX_NUMBERS == 1) {
            number = getNumber();
            printLargestNumbers(number, number);
            return EXIT_SUCCESS;
        } else {
            int counter = 0;
            while (counter < MAX_NUMBERS) {
                number = getNumber();

                if (number > maxValue) {
                    prevToMaxValue = maxValue;
                    maxValue = number;
                }

                if (number < maxValue && number > prevToMaxValue) {
                    prevToMaxValue = number;
                }

                ++counter;
            }

            printLargestNumbers(maxValue, prevToMaxValue);
        }
    }

    return EXIT_SUCCESS;
}
