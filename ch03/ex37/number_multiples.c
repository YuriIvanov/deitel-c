#include <stdio.h>
#include <stdlib.h>

#define SIGN_AS_STRING "$"
#define MAX_NUMBER_OF_SIGNS 500
#define NUMBER_OF_SIGNS_PER_LINE 50

int main(void) {
    int from = 1;
    while (from <= MAX_NUMBER_OF_SIGNS) {
        printf("%s ", SIGN_AS_STRING);

        if ((from % NUMBER_OF_SIGNS_PER_LINE) == 0) {
            puts("");
        }

        ++from;
    }

    return EXIT_SUCCESS;
}
