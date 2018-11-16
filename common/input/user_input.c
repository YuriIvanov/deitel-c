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

    const bool isMinValueEqualToIntMin = (minValue == INT_MIN) ? true : false;

    int integer = minValue;
    if (!isMinValueEqualToIntMin) {
        // Make it less to satisfy cycle condition
        // in case of incorrect user input.
        --integer;
    }

    do {
        printf("%s", prompt);

        const int scanfResult = scanf("%d", &integer);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (integer < minValue || integer > maxValue) {
            puts(error);
        }

        // Skip main check if min value is MIN_INT and user haven't entered correct integer into console.
        // This means that integer variable will still be containing INT_MIN and cycle check will be successful.
        // But this is incorrect in our case because scanf failed.
        if (scanfResult != 1 && isMinValueEqualToIntMin) {
            continue;
        }
    } while (integer < minValue || integer > maxValue);

    return integer;
}

double getDoubleFromUser(const double minValue,
                         const double maxValue,
                         const char* prompt,
                         const char* error) {
    assert(minValue <= maxValue);

    // TODO. Is it correct to compare double value with DBL_MIN?
    // Because floating point comparing is bad idea...
    const bool isMinValueEqualToDblMin = (minValue <= DBL_MIN) ? true : false;

    double d = minValue;
    if (!isMinValueEqualToDblMin) {
        // Make it less to satisfy cycle condition
        // in case of incorrect user input.
        d -= DBL_EPSILON;
    }

    do {
        printf("%s", prompt);

        const int scanfResult = scanf("%lf", &d);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (d < minValue || d > maxValue) {
            puts(error);
        }

        // Skip main check if min value is DBL_MIN and user haven't entered correct integer into console.
        // This means that integer variable will still be containing DBL_MIN and cycle check will be successful.
        // But this is incorrect in our case because scanf failed.
        if (scanfResult != 1 && isMinValueEqualToDblMin) {
            continue;
        }
    } while (d < minValue || d > maxValue);

    return d;
}
