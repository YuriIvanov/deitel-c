#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int currentNumber = 1;
    int columns = 1;
    int rows = 10;

    while (rows > 0) {
        int columnsInCurrentRowLeft = columns;
        while (columnsInCurrentRowLeft > 0) {
            printf("%d ", currentNumber);

            --columnsInCurrentRowLeft;
            ++currentNumber;
        }

        printf("%s", "\n");
        ++columns;
        --rows;
    }

    return EXIT_SUCCESS;
}
