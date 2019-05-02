#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_RANDOM_NUMBERS 10

static void initRandom(void) {
    srand(time(NULL));
}

int main(void) {
    initRandom();

    printf("%s", "Random integers from set (3, 6, 9, 12, 15, 18, 21, 24, 27, 30):\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        const int randomInt = (1 + (rand() % 10)) * 3;
        printf("%d\n", randomInt);
    }

    puts("");

    printf("%s", "Random integers from set (3, 5, 7, 9, 11, 13, 15, 17, 19):\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        const int randomInt = ((1 + (rand() % 9)) * 2) + 1;
        printf("%d\n", randomInt);
    }

    puts("");

    printf("%s", "Random integers from set (3, 8, 13, 18, 23, 28, 33):\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        const int randomInt = (((rand() % 7)) * 5) + 3;
        printf("%d\n", randomInt);
    }

    return EXIT_SUCCESS;
}
