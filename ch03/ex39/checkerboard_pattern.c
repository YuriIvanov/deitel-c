#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int currentRow = 1;
    while (currentRow <= 8) {
        if ((currentRow % 2) == 0) {
            printf("%s", " ");
        }

        int currentColumn = 1;
        while (currentColumn <= 8) {
            printf("%s", "* ");
            ++currentColumn;
        }

        puts("");
        ++currentRow;
    }

    return EXIT_SUCCESS;
}
