#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int getNumberOfValuesToInput(void) {
    int valuesToInput = 0;

    do {
        printf("%s", "Enter number of values you want to get average from (1-20): ");

        int scanfResult = scanf("%d", &valuesToInput);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (valuesToInput <= 0 || valuesToInput > 20) {
            puts("You've entered incorrect number. Try again.");
        }
    } while(valuesToInput <= 0 || valuesToInput > 20);

    return valuesToInput;
}

static int getNumber(void) {
    int number = 0;

    int scanfResult = 0;
    while (scanfResult != 1) {
        printf("%s", "Enter integer number: ");
        scanfResult = scanf("%d", &number);

        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect number. Try again.");
        }
    }

    return number;
}

static void printAverage(const int sum, const int numberOfValues) {
    printf("Average value of numbers you've entered is: %.2f\n", (double) sum / numberOfValues);
}

int main(void) {
    const int numberOfValuesToInput = getNumberOfValuesToInput();
    int sum = 0;

    for (int i = numberOfValuesToInput; i > 0; --i) {
        const int number = getNumber();
        sum += number;
    }

    printAverage(sum, numberOfValuesToInput);

    return 0;
}
