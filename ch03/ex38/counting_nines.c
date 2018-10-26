#include <stdio.h>
#include <stdlib.h>

long getNumber(void) {
    long number = 0;

    printf("Enter integer number: ");
    scanf("%ld", &number);

    return number;
}

int countNines(const long number) {
    int nines = 0;

    long currentNumber = number;
    while (currentNumber != 0) {
        const int digit = currentNumber % 10;

        if (digit == 9) {
            ++nines;
        }

        currentNumber /= 10;
    }
    return nines;
}

int main(void) {
    const long number = getNumber();
    const int nines = countNines(number);

    printf("Number %ld contains %d nines\n", number, nines);

    return EXIT_SUCCESS;
}
