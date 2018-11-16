#include <stdio.h>
#include <stdlib.h>

#define MAX_PI_TERMS 150

// Calculating Pi Using an Gregory-Leibniz series.
static double calculatePi(const int maxTerms) {
    const double PI_TERMS_NUMENATOR = 4.0;
    double piTermsDenominator = 1.0;

    double piTermsResult = 0;
    for (int piTermCounter = 0; piTermCounter < maxTerms; ++piTermCounter) {
        const double piTermValue = PI_TERMS_NUMENATOR / piTermsDenominator;
        if (piTermCounter % 2 == 0) {
            piTermsResult += piTermValue;
        } else {
            piTermsResult -= piTermValue;
        }
        piTermsDenominator += 2.0;
    }

    return piTermsResult;
}

int main(void) {
    printf("%5s %8s\n", "Terms", "Pi value");
    for (int piTermsCounter = 1; piTermsCounter <= MAX_PI_TERMS; ++piTermsCounter) {
        printf("%5d %8.6f\n", piTermsCounter, calculatePi(piTermsCounter));
    }

    return EXIT_SUCCESS;
}
