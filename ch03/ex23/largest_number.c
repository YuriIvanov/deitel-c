#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10

int max(const int a, const int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int getNumber(void) {
    int number = 0;

    printf("%s", "Enter positive integer number: ");
    scanf("%d", &number);

    while (number < 0) {
        puts("You have entered incorrect number. Try again.");

        printf("%s", "Enter positive integer number: ");
        scanf("%d", &number);
    }

    return number;
}

void printLargestNumber(const int largestNumber) {
    printf("Largest number is: %d\n", largestNumber);
}

int main() {
    int largestNumber = 0;

    int counter = 0;
    while (counter < MAX_NUMBERS) {
        const int number = getNumber();

        largestNumber = max(number, largestNumber);

        ++counter;
    }

    printLargestNumber(largestNumber);

    return EXIT_SUCCESS;
}
