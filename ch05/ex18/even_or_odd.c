#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int getInteger() {
    int integer = 0;

    int scanfResult = 0;
    do {
        printf("%s", "Enter integer value (Ctrl+C to exit): ");

        scanfResult = scanf("%d", &integer);
        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect integer value. Try again.");
        }
    } while (scanfResult != 1);

    return integer;
}

static bool isEven(const int number) {
    return number % 2 == 0;
}

int main(void) {
    while (true) {
        const int integer = getInteger();

        if (isEven(integer)) {
            puts("Number you have entered is even.");
        } else {
            puts("Number you have entered is odd.");
        }
    }


    return EXIT_SUCCESS;
}
