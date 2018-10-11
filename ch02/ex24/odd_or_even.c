#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 0;

    printf("%s", "Enter integer number: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        puts("Number you have entered is even.");
    }

    if (number % 2 != 0) {
        puts("Number you have entered is odd.");
    }

    return EXIT_SUCCESS;
}
