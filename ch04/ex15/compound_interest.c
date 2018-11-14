#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void printHeader(const double rate) {
    printf(
        "Compound-interest for rate: %.2f\n"
        "%4s%21s\n",
        rate,
        "Year",
        "Amount on deposit");
}

static void calculateAndPrintCompoundInterest(const double principal, const double rate) {
    for (unsigned int year = 1; year <= 10; ++year) {
        double amount = principal * pow(1.0 + rate, year);
        printf("%4u%21.2f\n", year, amount);
    }
}

int main(void) {
    double principal = 1000.0;
    double rate = .05;

    for (int i = 0; i < 6; ++i) {
        printHeader(rate);
        calculateAndPrintCompoundInterest(principal, rate);

        rate += 0.01;

        puts("");
    }

    return EXIT_SUCCESS;
}
