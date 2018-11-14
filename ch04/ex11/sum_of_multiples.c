#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool isMultipleOfSeven(const int number) {
    if ((number % 7) == 0) {
        return true;
    }

    return false;
}

int main(void) {
    int sum = 0;
    for (int number = 1; number <= 100; ++number) {
        if (isMultipleOfSeven(number)) {
            sum += number;
        }
    }

    printf("Sum of all multiplies of seven from 1 to 100 is: %d\n", sum);

    return EXIT_SUCCESS;
}
