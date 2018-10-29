#include <stdio.h>
#include <stdlib.h>

int getPrecision(void) {
    int number = -1;

    while (number < 0) {
        printf("%s", "Enter e constant precision: ");
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

float e_constant(const int precision) {
    float e = 1.0;

    int counter = 1;
    while (counter <= precision) {
        e += 1.0 / factorial(counter);
        ++counter;
    }

    return e;
}

int main(void) {
    const int precision = getPrecision();

    printf("e constant with precision %d is %f\n", precision, e_constant(number));

    return EXIT_SUCCESS;
}
