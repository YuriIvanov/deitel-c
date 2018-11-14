#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_CUSTOMERS 3

static int getCustomerAccountNumber(void) {
    int accountNumber = -1;

    do {
        printf("%s", "Enter customer's account number: ");
        int scanfResult = scanf("%d", &accountNumber);

        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (accountNumber <= 0) {
            puts("You've entered incorrect number. Try again.");
        }
    } while (accountNumber <= 0);

    return accountNumber;
}

static int getCustomerCreditLimitBeforeRecession(void) {
    int creditLimit = -1;

    do {
        printf("%s", "Enter customer's credit limit before recession: ");
        int scanfResult = scanf("%d", &creditLimit);

        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (creditLimit < 0) {
            puts("You've entered incorrect limit. Try again.");
        }
    } while (creditLimit < 0);

    return creditLimit;
}

static int getCustomerCurrentBalance(void) {
    int currentBalance = -1;

    do {
        printf("%s", "Enter customer's current balance: ");
        int scanfResult = scanf("%d", &currentBalance);

        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (currentBalance < 0) {
            puts("You've entered incorrect customer balance. Try again.");
        }
    } while (currentBalance < 0);

    return currentBalance;
}

static void calculateAndPrintNewCreditLimit(
    const int accountNumber,
    const int creditLimitBeforeRecession,
    const int currentBalance) {
    const int newCreditLimit = creditLimitBeforeRecession / 2;

    printf("Now customer %d has credit limit %d\n", accountNumber, newCreditLimit);
    if (currentBalance > newCreditLimit) {
        printf("Warning!!! Customer's balance (%d) exceeds new credit limit (%d)!\n", currentBalance, newCreditLimit);
    }
}

int main(void) {
    for (int customer = 1; customer <= NUMBER_OF_CUSTOMERS; ++customer) {
        const int accountNumber = getCustomerAccountNumber();
        const int creditLimitBeforeRecession = getCustomerCreditLimitBeforeRecession();
        const int customerCurrentBalance = getCustomerCurrentBalance();

        calculateAndPrintNewCreditLimit(accountNumber, creditLimitBeforeRecession, customerCurrentBalance);
    }

    return EXIT_SUCCESS;
}
