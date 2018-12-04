#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <assert.h>

#include "user_input.h"

int getIntFromUser(const int minValue,
                   const int maxValue,
                   const char* prompt,
                   const char* error) {
    assert(minValue <= maxValue);

    int integer = minValue;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", prompt);
        const int scanfResult = scanf("%d", &integer);

        isUserInputValid =
            scanfResult == 1 &&
            integer >= minValue && integer <= maxValue;

        if (!isUserInputValid) {
            fflush(stdin);
            puts(error);
        }
    };

    return integer;
}

double getDoubleFromUser(const double minValue,
                         const double maxValue,
                         const char* prompt,
                         const char* error) {
    assert(minValue <= maxValue);

    double d = minValue;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", prompt);
        const int scanfResult = scanf("%lf", &d);

        // I know that using equality with floating number is bad idea...
        isUserInputValid =
            scanfResult == 1 &&
            d >= minValue && d <= maxValue;

        if (!isUserInputValid) {
            fflush(stdin);
            puts(error);
        }
    }

    return d;
}
