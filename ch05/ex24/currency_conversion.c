#include <stdio.h>
#include <stdlib.h>

#define USD_TO_YEN_COURSE 118.87
#define USD_TO_EURO_COURSE 0.92

#define NUMBER_OF_DOLLAR_AMOUNTS 10

static const double dollarAmounts[NUMBER_OF_DOLLAR_AMOUNTS] = {
    1.3, 7.4, 8.1, 4.4, 5.6, 1.8, 44.5, 8.23, 2.38, 173.26
};

static double toYen(const double usDollars) {
    return usDollars * USD_TO_YEN_COURSE;
}

static double toEuro(const double usDollars) {
    return usDollars * USD_TO_EURO_COURSE;
}

int main(void) {
    printf("%-7s   %-10s   %-7s\n", "Dollars", "Yens", "Euros");

    for (size_t i = 0; i < NUMBER_OF_DOLLAR_AMOUNTS; ++i) {
        const double dollarAmount = dollarAmounts[i];
        const double yenAmount = toYen(dollarAmount);
        const double euroAmount = toEuro(dollarAmount);

        printf(
            "%-7.2lf   %-10.2lf   %-7.2lf\n",
            dollarAmount,
            yenAmount,
            euroAmount);
    }

    return EXIT_SUCCESS;
}
