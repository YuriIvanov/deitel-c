#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MIN_NUMBER_VALUE 0
#define MAX_NUMBER_VALUE INT_MAX

static int getNumber() {
    int number = MIN_NUMBER_VALUE;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("Enter integer value between %d and %d (Ctrl+C to exit): ",
               MIN_NUMBER_VALUE,
               MAX_NUMBER_VALUE);
        const int scanfResult = scanf("%d", &number);

        isUserInputValid =
            scanfResult == 1 &&
            number >= MIN_NUMBER_VALUE && number <= MAX_NUMBER_VALUE;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect integer value. Try again.");
        }
    }

    return number;
}

static long sumOfDigits(const int number) {
    if (0 == number) {
        return 0;
    }

    return number % 10 + sumOfDigits(number / 10);
}

int main(void) {
    while (true) {
        const int number = getNumber();
        printf("Sum of digits of number %d is: %ld\n\n", number, sumOfDigits(number));
    }

    return EXIT_SUCCESS;
}
