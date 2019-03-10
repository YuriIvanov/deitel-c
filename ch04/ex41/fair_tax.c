#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define FAIR_TAX_PERCENTAGE (0.23)

static double getExpenses(const char* expensesName) {
    double expenses = -1.0;

    do {
        printf("Enter your %s expenses: ", expensesName);

        const int scanfResult = scanf("%lf", &expenses);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (expenses < 0.0) {
            printf("You've entered incorrect %s expenses amount. Try again.", expensesName);
        }
    } while (expenses < 0.0);

    return expenses;
}

static double getHousingExpenses(void) {
    return getExpenses("housing");
}

static double getFoodExpenses(void) {
    return getExpenses("food");
}

static double getClothingExpenses(void) {
    return getExpenses("clothing");
}

static double getExpensesSum(const int numberOfExpenses, va_list expenses) {
    double expensesSum = 0.0;
    for (int counter = 0; counter < numberOfExpenses; ++counter) {
        expensesSum += va_arg(expenses, double);
    }

    return expensesSum;
}

static double calculateFairTax(const int numberOfExpenses, ...) {
    va_list expenses;
    va_start(expenses, numberOfExpenses);

    double expensesSum = getExpensesSum(numberOfExpenses, expenses);

    va_end(expenses);

    return expensesSum * FAIR_TAX_PERCENTAGE;
}

static void showFairTax(const double fairTax) {
    printf("Your fair tax is: %.2lf$.\n", fairTax);
}

int main(void) {
    const double housingExpenses = getHousingExpenses();
    const double foodExpenses = getFoodExpenses();
    const double clothingExpenses = getClothingExpenses();

    const double fairTax = calculateFairTax(3, housingExpenses, foodExpenses, clothingExpenses);

    showFairTax(fairTax);

    return EXIT_SUCCESS;
}
