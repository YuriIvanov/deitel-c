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

    printf("%s", "Random integers in range 1 <= n <= 6:\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        printf("%d\n", 1 + rand() % 6);
    }

    printf("%s", "\nRandom integers in range 100 <= n <= 1000:\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        printf("%d\n", 100 + rand() % 901);
    }

    printf("%s", "\nRandom integers in range 0 <= n <= 19:\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        printf("%d\n", rand() % 20);
    }

    printf("%s", "\nRandom integers in range 1000 <= n <= 2222:\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        printf("%d\n", 1000 + rand() % 1223);
    }

    printf("%s", "\nRandom integers in range -1 <= n <= 1:\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        printf("%d\n", -1 + rand() % 3);
    }

    printf("%s", "\nRandom integers in range -3 <= n <= 11:\n");
    for (int i = 0; i < MAX_RANDOM_NUMBERS; ++i) {
        printf("%d\n", -3 + rand() % 15);
    }

    return EXIT_SUCCESS;
}
