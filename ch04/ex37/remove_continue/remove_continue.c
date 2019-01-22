#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (unsigned int x = 1; x <= 10; ++x) {
        if (x != 5) {
            printf("%u ", x);
        }
    }

    puts("\nUsed logical condition negation to skip printing the value 5");

    return EXIT_SUCCESS;
}

