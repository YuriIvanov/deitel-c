#include <stdio.h>
#include <stdlib.h>

int getAccountNumber(void) {
    int accountNumber = -1;

    printf("%s", "Enter account number (-1 to end): ");
    scanf("%d", &accountNumber);

    return accountNumber;
}

int getMortgageAmountInDollars(void) {
    int mortgageAmount = 0;

    printf("%s", "Enter mortgage amount (in dollars): ");
    scanf("%d", &mortgageAmount);

    return mortgageAmount;
}

int getMortgageTermInYears(void) {
    int mortgageTerm = 0;

    printf("%s", "Enter mortgage term (in years): ");
    scanf("%d", &mortgageTerm);

    return mortgageTerm;
}

float getInterestRate(void) {
    float interestRate = 0.0;

    printf("%s", "Enter interest rate (as decimal): ");
    scanf("%f", &interestRate);

    return interestRate;
}

int calculateMonthlyPayableInterest(const int mortgageAmountInDollars,
                                    const int mortgageTermInYears,
                                    const float interestRate) {
    float totalInterestPayable = mortgageAmountInDollars * mortgageTermInYears * interestRate;
    float totalAmountPayable = mortgageAmountInDollars + totalInterestPayable;
    int monthlyPayableInterestInDollars = totalAmountPayable / (mortgageTermInYears * 12);

    return monthlyPayableInterestInDollars;
}

void printMonthlyPayableInterest(const int monthlyPayableInterest) {
    printf("The monthly payable interest $ %d\n\n", monthlyPayableInterest);
}

int main(void) {
    int accountNumber = getAccountNumber();
    while (accountNumber != -1) {
        const int mortgageAmountInDollars = getMortgageAmountInDollars();
        const int mortgageTermInYears = getMortgageTermInYears();
        const float interestRate = getInterestRate();

        int monthlyPayableInterestInDollars =
            calculateMonthlyPayableInterest(mortgageAmountInDollars, mortgageTermInYears, interestRate);
        printMonthlyPayableInterest(monthlyPayableInterestInDollars);

        accountNumber = getAccountNumber();
    }

    return EXIT_SUCCESS;
}
