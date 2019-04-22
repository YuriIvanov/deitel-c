#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int x;

    for (x = 1; x <= 10 && x != 5; ++x) {
        printf("%u ", x);
    }

    printf("\nBroke out of loop at x == %u\n", x);

    return EXIT_SUCCESS;
}
