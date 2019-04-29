#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static double roundToInteger(const double number) {
    return floor(number+ 0.5);
}

static double roundToTenths(const double number) {
    return floor(number * 10 + 0.5) / 10;
}

static double roundToHundreths(const double number) {
    return floor(number * 100 + 0.5) / 100;
}

static double roundToThousandths(const double number) {
    return floor(number * 1000 + 0.5) / 1000;
}

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
        printf(
            "\n%s: %.6lf"
            "\n%s: %.0lf"
            "\n%s: %.1lf"
            "\n%s: %.2lf"
            "\n%s: %.3lf\n\n",
            "Original number", numberToRound,
            "Rounded to integer", roundToInteger(numberToRound),
            "Rounded to tenths", roundToTenths(numberToRound),
            "Rounded to hundredths", roundToHundreths(numberToRound),
            "Rounded to thousandths", roundToThousandths(numberToRound)
        );
    }

    return EXIT_SUCCESS;
}
