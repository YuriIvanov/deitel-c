#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE 1
#define MAX_VALUE 10

int main() {
    printf("N\tN2\tN3\tN4\n\n");

    int value = MIN_VALUE;
    while (value <= MAX_VALUE) {
        printf(
            "%d\t%d\t%d\t%d\n",
            value,
            value * value,
            value * value * value,
            value * value * value * value);

        ++value;
    }

    return EXIT_SUCCESS;
}
