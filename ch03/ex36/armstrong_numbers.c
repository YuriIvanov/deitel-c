#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

int getNumberOfDigits(const int number) {
    int numberOfDigits = 0;
    int currentNumber = number;

    // Each number has at least one digit. That's why we use do/while cycle.
    do {
        ++numberOfDigits;
        currentNumber /= 10;
    } while (currentNumber != 0);

    return numberOfDigits;
}

long long calculateArmstrongSum(const int number) {
    long long sum = 0;
    int currentNumber = number;
    const int numberOfDigits = getNumberOfDigits(number);

    while (currentNumber != 0) {
        const int digit = currentNumber % 10;

        sum += intPow(digit, numberOfDigits);

        currentNumber /= 10;
    }

    return sum;
}

bool isArmstrongNumber(const int number) {
    const long long numberArmstrongSum = calculateArmstrongSum(number);
    if (numberArmstrongSum == number) {
        return true;
    }
    return false;
}

void processNumber(const int number) {
    if (isArmstrongNumber(number)) {
        printf("%d\n", number);
    }
}

int main(void) {
    int from = 1;
    const int to = 100000;

    printf("Armstrong numbers from %d up to %d:\n", from, to);

    while (from <= to) {
        processNumber(from);
        ++from;
    }

    return EXIT_SUCCESS;
}
