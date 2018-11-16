#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

static unsigned long long convertPositiveDecimalToBinary(const int decimal) {
    unsigned long long binaryNumber = 0;
    int currentDecimal = decimal;
    int remainder;
    int factor = 1;

    while (currentDecimal != 0) {
        remainder = currentDecimal % 2;
        currentDecimal /= 2;
        binaryNumber += remainder * factor;
        factor *= 10;
    }
    return binaryNumber;
}

int main(void) {
    printf("%7s %13s %5s %11s\n", "Decimal", "Binary", "Octal", "Hexadecimal");
    for (unsigned int number = 1; number <= 256; ++number) {
        printf(
            "%7u %13llu %5o %11X\n",
            number,
            convertPositiveDecimalToBinary(number),
            number,
            number);
    }

    return EXIT_SUCCESS;
}
