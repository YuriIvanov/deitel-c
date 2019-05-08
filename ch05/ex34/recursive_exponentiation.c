#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int getBase() {
    int base = 0;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", "Enter base integer value you want to exponent (Ctrl+C to exit): ");
        const int scanfResult = scanf("%d", &base);

        isUserInputValid = scanfResult == 1;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect base integer value. Try again.");
        }
    }

    return base;
}

static int getExponent() {
    int exponent = 0;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", "Enter exponent (Ctrl+C to exit): ");
        const int scanfResult = scanf("%d", &exponent);

        isUserInputValid = scanfResult == 1;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect exponent value. Try again.");
        }
    }

    return exponent;
}

static long long power(const int base, const int exponent) {
    if (0 == exponent) {
        if (base >= 0) {
            return 1;
        } else {
            return -1;
        }
    }

    if (1 == exponent) {
        return base;
    }

    return base * power(base, exponent - 1);
}

int main(void) {
    while (true) {
        const int base = getBase();
        const int exponent = getExponent();
        printf("Power result is: %lld\n\n", power(base, exponent));
    }

    return EXIT_SUCCESS;
}
