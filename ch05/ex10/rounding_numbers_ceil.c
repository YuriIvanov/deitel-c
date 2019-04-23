#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

static double getNumberToRound() {
    double numberToRound = 0.0;

    int scanfResult = -1;
    do {
        printf("%s", "Enter number to round (Ctrl+C to exit): ");

        scanfResult = scanf("%lf", &numberToRound);
        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect number to round. Try again.");
        }
    } while (scanfResult != 1);

    return numberToRound;
}

int main(void) {
    while (true) {
        const double numberToRound = getNumberToRound();
        const double roundedNumber = ceil(numberToRound - 0.5);
        printf("Rounded to nearest integer: %.2lf\n", roundedNumber);
    }

    return EXIT_SUCCESS;
}
