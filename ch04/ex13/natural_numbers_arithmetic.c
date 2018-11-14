#include <stdio.h>
#include <stdlib.h>

static int getUpperLimit(void) {
    int number = 0;

    int scanfResult = 0;
    while (scanfResult != 1) {
        printf("%s", "Enter upper limit as integer number: ");
        scanfResult = scanf("%d", &number);

        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect number. Try again.");
        }
    }

    return number;
}

int main(void) {
    unsigned long long sum = 0;
    unsigned long long squaresSum = 0;
    unsigned long long cubesSum = 0;

    const int upperLimit = getUpperLimit();
    for (int number = 1; number <= upperLimit; ++number) {
        sum += number;
        squaresSum += number * number;
        cubesSum += number * number * number;
    }

    printf(
        "Number from: %d\n"
        "Upper limit: %d\n"
        "Sum of numbers: %llu\n"
        "Sum of numbers squares: %llu\n"
        "Sum of numbers cubes: %llu\n",
        1,
        upperLimit,
        sum,
        squaresSum,
        cubesSum);

    return EXIT_SUCCESS;
}
