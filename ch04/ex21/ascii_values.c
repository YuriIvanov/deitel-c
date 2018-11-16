#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int character = 0; character <= 127; ++character) {
        printf("%c ", character);

        if (character != 0 && (character % 10 == 0)) {
            puts("");
        }
    }


    return EXIT_SUCCESS;
}
