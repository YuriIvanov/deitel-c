#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static double getHousingExpenses(void) {
    return 0.0;
}

static double getFoodExpenses(void) {
    return 0.0;
}

static double getClothingExpenses(void) {
    return 0.0;
}

static double calculateFairTax(const int rightmostArg, ...) {
    return 0.0;
}

int main(void) {
    const double housingExpenses = getHousingExpenses();
    const double foodExpenses = getFoodExpenses();
    const double clothingExpenses = getClothingExpenses();

    const double fairTax = calculateFairTax(0, housingExpenses, foodExpenses, clothingExpenses);

    return EXIT_SUCCESS;
}
