#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER 1000

static bool isPerfect(const int number) {
    return true;
}

int main(void) {
    for (int number = 1; number <= MAX_NUMBER; ++number) {
        const bool perfect = isPerfect(number);

        if (perfect) {
            printf("Number %d is perfect number.", number);
        } else {
            printf("Number %d is not a perfect number.", number);
        }
        puts("\n");
    }

    return EXIT_SUCCESS;
}
