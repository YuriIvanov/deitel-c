#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define integral_money_t long long int

static integral_money_t dollarsToCents(const integral_money_t dollarAmount) {
    return dollarAmount * 100;
}

static integral_money_t centsAmountToDollarPortion(const integral_money_t centsAmount) {
    return centsAmount / 100;
}

static integral_money_t centsAmountToCentsPortion(const integral_money_t centsAmount) {
    return centsAmount % 100;
}

int main(void) {
    const integral_money_t principalInCents = dollarsToCents(1000) ;
    const double rate = 0.05;

    printf("%4s%21s\n", "Year", "Amount on deposit");
    for (int year = 1; year <= 10; ++year) {
        const integral_money_t amountInCents = principalInCents * pow(1.0 + rate, year);
        const integral_money_t dollars = centsAmountToDollarPortion(amountInCents);
        const integral_money_t cents = centsAmountToCentsPortion(amountInCents);

        printf("%4d%18lld.%02lld\n", year, (long long int) dollars, (long long int) cents);
    }

    return EXIT_SUCCESS;
}
