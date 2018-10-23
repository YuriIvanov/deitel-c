#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int getNumber(void) {
    int number = 0;

    printf("%s", "Enter positive integer number (-1 to end): ");
    scanf("%d", &number);

    return number;
}

bool isNumberPrime(const int number) {
    if (number <= 1) {
        return false;
    }

    int n = 2;
    while (n <= sqrt(number)) {
        if ((number % n) == 0) {
            return false;
        }
        ++n;
    }

    return true;
}

void printNumberIsPrime(const int number, const bool isNumberPrime) {
    if (isNumberPrime) {
        printf("Number %d is prime\n\n", number);
    } else {
        printf("Number %d is not prime\n\n", number);
    }
}

int main() {
    int number = getNumber();
    while (number != -1) {
        const bool isPrime = isNumberPrime(number);
        printNumberIsPrime(number, isPrime);

        number = getNumber();
    }

    return EXIT_SUCCESS;
}
