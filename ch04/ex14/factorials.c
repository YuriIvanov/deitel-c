#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(const int number) {
    if (number < 0) {
        // As error.
        return -1;
    }

    if (number == 0) {
        return 1;
    }

    unsigned long long factorial = 1;
    int currentNumber = number;
    while(currentNumber > 0) {
        factorial *= currentNumber;
        --currentNumber;
    }

    return factorial;
}

int main(void) {
    printf("%-7s%s\n", "Number", "Factorial");
    for (int number = 1; number <= 20; ++number) {
        printf("%-7d%llu\n", number, factorial(number));
    }

    return EXIT_SUCCESS;
}
