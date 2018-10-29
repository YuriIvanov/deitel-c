#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int intPow(const int base, const int exp) {
    int currentBase = base;
    int currentExp = exp;

    int result = 1;
    while (currentExp) {
        if (currentExp & 1) {
            result *= currentBase;
        }
        currentExp /= 2;
        currentBase *= currentBase;
    }
    return result;
}

int getExponentBase(void) {
    int number = -1;

    while (number < 0) {
        printf("%s", "Enter e exponent base: ");
        scanf("%d", &number);

        if (number < 0) {
            puts("You've entered incorrect number. Please, try again.");
        }
    }

    return number;
}

int getExponentPrecision(void) {
    int number = -1;

    while (number < 0) {
        printf("%s", "Enter e exponent precision: ");
        scanf("%d", &number);

        if (number < 0) {
            puts("You've entered incorrect number. Please, try again.");
        }
    }

    return number;
}

unsigned long factorial(const int number) {
    if (number < 0) {
        // As error.
        return -1;
    }

    if (number == 0) {
        return 1;
    }

    unsigned long factorial = 1;
    int currentNumber = number;
    while(currentNumber > 0) {
        factorial *= currentNumber;
        --currentNumber;
    }

    return factorial;
}

float e_exponent(const int e_base, const int precision) {
    float e = 1.0;

    int counter = 1;
    while (counter <= precision) {
        e += i(e_base, counter) / factorial(counter);

        ++counter;
    }

    return e;
}

int main(void) {
    const int e_base = getExponentBase();
    const int e_precision = getExponentPrecision();

    printf(
        "e exponent with base %d and precision %d is %f\n",
        e_base,
        e_precision,
        e_exponent(e_base, e_precision));

    return EXIT_SUCCESS;
}
