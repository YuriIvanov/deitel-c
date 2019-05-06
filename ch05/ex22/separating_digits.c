#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MIN_NUMBER_VALUE INT_MIN
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

static void printSeparateDigitsRecursiveHelper(const int number) {
    if (0 == number) {
        return;
    }

    printSeparateDigitsRecursiveHelper(number / 10);

    printf("%d ", abs(number % 10));
}

static void printSeparateDigits(const int number) {
    // Here we handle special cases.
    if (0 == number) {
        printf("%d", 0);
    }

    if (number < 0) {
        printf("%s", "- ");
    }

    printSeparateDigitsRecursiveHelper(number);
}

int main(void) {
    while (true) {
        const int number = getNumber();
        printSeparateDigits(number);
        puts("\n");
    }

    return EXIT_SUCCESS;
}
