#include <stdio.h>
#include <stdlib.h>

#define WEEKLY_SALARY 200.0
#define GROSS_SALES_PERCENT 0.09

float getSalesInDollars(void) {
    float salesInDollars = 0;

    printf("%s", "Enter sales in dollars (-1 to end): ");
    scanf("%f", &salesInDollars);

    return salesInDollars;
}

float calculateSalary(const float salesInDollars) {
    return (WEEKLY_SALARY) + (salesInDollars * GROSS_SALES_PERCENT);
}

void printSalary(const float salary) {
    printf("Salary is: $%.2f\n\n", salary);
}

int main() {
    float salesInDollars = getSalesInDollars();

    // Comparing floats for equality is bad idea. But exercise forces us to do this...
    while ((int) salesInDollars != -1) {
        float salary = calculateSalary(salesInDollars);
        printSalary(salary);

        salesInDollars = getSalesInDollars();
    }

    return EXIT_SUCCESS;
}
