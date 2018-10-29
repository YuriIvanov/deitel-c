#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(void) {
    int number = -1;

    while (number < 0) {
        printf("%s", "Enter positive number: ");
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

int main(void) {
    const int number = getPositiveNumber();

    printf("%d! is %lu\n", number, factorial(number));

    return EXIT_SUCCESS;
}
