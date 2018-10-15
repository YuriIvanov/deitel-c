#include <stdio.h>
#include <stdlib.h>

#define COUNTY_TAX_PERCENT 0.05
#define STATE_TAX_PERCENT 0.04

int getTotalAmountCollected(void) {
    int totalAmountCollected = 0;

    printf("%s", "Enter total amount collected (-1 to quit): ");
    scanf("%d", &totalAmountCollected);

    return totalAmountCollected;
}

void getMonth(char *month, const int maxMonthLength) {
    printf("%s", "Enter name of month: ");
    fflush(stdin);
    fgets(month, maxMonthLength, stdin);
}

void calculateAndPrintSalesTax(const int totalAmountCollected) {
    char month[256] = {0};
    getMonth(month, sizeof(month));

    const float totalCollections = (float) totalAmountCollected;
    const float countySalesTax = totalCollections * COUNTY_TAX_PERCENT;
    const float stateSalesTax = totalCollections * STATE_TAX_PERCENT;
    const float totalSalesTaxCollected = countySalesTax + stateSalesTax;
    const float sales = totalCollections - totalSalesTaxCollected;

    printf("Total Collections: $ %.2f\n"
           "Sales: $ %.2f\n"
           "County Sales Tax: $ %.2f\n"
           "State Sales Tax: $ %.2f\n"
           "Total Sales Tax Collected: $ %.2f\n\n",
           totalCollections,
           sales,
           countySalesTax,
           stateSalesTax,
           totalSalesTaxCollected);
}

int main(void) {
    int totalAmountCollected = 0;

    totalAmountCollected = getTotalAmountCollected();
    while (totalAmountCollected != -1) {
        calculateAndPrintSalesTax(totalAmountCollected);

        totalAmountCollected = getTotalAmountCollected();
    }

    return EXIT_SUCCESS;
}


