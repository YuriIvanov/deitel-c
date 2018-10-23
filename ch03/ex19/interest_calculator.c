#include <stdio.h>
#include <stdlib.h>

float getLoanPrincipal(void) {
    float loanPrincipal = 0.0;

    printf("%s", "Enter loan principal (-1 to end): ");
    scanf("%f", &loanPrincipal);

    return loanPrincipal;
}

float getInterestRate(void) {
    float interestRate = 0.0;

    printf("%s", "Enter interest rate: ");
    scanf("%f", &interestRate);

    return interestRate;
}

int getloanTermsInDays(void) {
    int loanTermsInDays = 0;

    printf("%s", "Enter term of the loan in days: ");
    scanf("%d", &loanTermsInDays);

    return loanTermsInDays;
}

float calculateInterestCharge(const float loanPrincipal,
                              const float interestRate,
                              const int loanTermsInDays) {
    return loanPrincipal * interestRate * loanTermsInDays / 365;
}

void printInterestCharge(const float interestCharge) {
    printf("The interest charge is $%.2f\n\n", interestCharge);
}

int main() {
    float loanPrincipal = getLoanPrincipal();

    // Comparing floats for equality is bad idea. But exercise forces us to do this...
    while ((int) loanPrincipal != -1) {
        float interestRate = getInterestRate();
        int loanTermsInDays = getloanTermsInDays();

        float interestCharge = calculateInterestCharge(loanPrincipal, interestRate, loanTermsInDays);
        printInterestCharge(interestCharge);

        loanPrincipal = getLoanPrincipal();
    }

    return EXIT_SUCCESS;
}
