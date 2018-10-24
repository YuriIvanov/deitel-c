#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_CYCLES 5
#define INITIAL_VALUE 7
#define VALUE_STEP 3

int main() {
    printf(
        "A\tA+%d\tA+%d\tA+%d\n\n",
        VALUE_STEP,
        VALUE_STEP * 2,
        VALUE_STEP * 3);

    int value = INITIAL_VALUE;
    int counter = 0;
    while (counter < NUMBER_OF_CYCLES) {
        printf(
            "%d\t%d\t%d\t%d\n",
            value,
            value + VALUE_STEP,
            value + (VALUE_STEP * 2),
            value + (VALUE_STEP * 3));

        value += INITIAL_VALUE;
        ++counter;
    }

    return EXIT_SUCCESS;
}
