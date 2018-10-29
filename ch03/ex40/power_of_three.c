#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long positiveIntPow(const int base, const int exp) {
    int currentBase = base;
    int currentExp = exp;

    unsigned long result = 1;
    while (currentExp) {
        if (currentExp & 1) {
            result *= currentBase;
        }
        currentExp /= 2;
        currentBase *= currentBase;
    }
    return result;
}

int main(void) {
    int pow = 1;
    while (true) {
        printf("%lu\n", positiveIntPow(3, pow));
        ++pow;
    }

    return EXIT_SUCCESS;
}
