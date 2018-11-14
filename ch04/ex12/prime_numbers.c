#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static bool isNumberPrime(const int number) {
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

int main(void) {
    for (int number = 0; number <= 100; ++number) {
        if (isNumberPrime(number)) {
            printf("%d\n", number);
        }
    }

    return EXIT_SUCCESS;
}
