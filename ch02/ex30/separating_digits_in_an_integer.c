#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 0;

    printf("%s", "Enter 5 digit integer number: ");
    scanf("%d", &number);

    int firstDigit = number / 10000 % 10;
    int secondDigit = number / 1000 % 10;
    int thirdDigit = number / 100 % 10;
    int fourthDigit = number / 10 % 10;
    int fifthDigit = number % 10;

    printf("%d   %d   %d   %d   %d", firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit);

    return EXIT_SUCCESS;
}
