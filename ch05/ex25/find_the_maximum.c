#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static float getFloat(const char *promtFloatNumber) {
    float floatNumber = 0;

    int scanfResult = 0;
    do {
        printf("Enter %s float value (Ctrl+C to exit): ", promtFloatNumber);

        scanfResult = scanf("%f", &floatNumber);
        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect float value. Try again.");
        }
    } while (scanfResult != 1);

    return floatNumber;
}

static float maxFloat(const float a, const float b, const float c, const float d) {
    float max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    if (d > max) {
        max = d;
    }

    return max;
}

int main(void) {
    while (true) {
        const float firstFloatNumber = getFloat("first");
        const float secondFloatNumber = getFloat("second");
        const float thirdFloatNumber = getFloat("third");
        const float fourthFloatNumber = getFloat("fourth");

        const float maxFloatNumber = maxFloat(firstFloatNumber,
                                              secondFloatNumber,
                                              thirdFloatNumber,
                                              fourthFloatNumber);
        printf("Maximum float of four entered is: %.2f\n\n", maxFloatNumber);
    }

    return EXIT_SUCCESS;
}
