#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Binary numbers can represent negative value too
// but for simplicity we assume only positive numbers in this exercise.

#define binary_num_t unsigned long
#define BINARY_NUM_T_MAX LONG_MAX
#define BINARY_NUM_T_FORMAT_SPECIFIER "%lu"

bool isBinaryNumber(const binary_num_t number) {
    binary_num_t currentNumber = number;
    while (currentNumber != 0) {
        const int digit = currentNumber % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }

        currentNumber /= 10;
    }
    return true;
}

binary_num_t getBinaryNumber(void) {
    binary_num_t number = BINARY_NUM_T_MAX;

    printf("%s", "Enter integer in binary format: ");
    scanf(BINARY_NUM_T_FORMAT_SPECIFIER, &number);
    while (!isBinaryNumber(number)) {
        puts("You've entered incorrect binary number. Please, try again.");

        printf("%s", "Enter integer in binary format: ");
        scanf(BINARY_NUM_T_FORMAT_SPECIFIER, &number);
    }

    return number;
}

int convertBinaryNumberToDecimal(const binary_num_t binaryNumber) {
    int decimalValue = 0;
    int power = 0;

    binary_num_t currentBinaryNumber = binaryNumber;
    while (currentBinaryNumber != 0) {
        const int digit = currentBinaryNumber % 10;

        decimalValue += digit * pow(2, power);

        ++power;
        currentBinaryNumber /= 10;
    }

    return decimalValue;
}

void printBinaryNumberAsDecimal(const binary_num_t binaryNumber) {
    const int decimalValue = convertBinaryNumberToDecimal(binaryNumber);

    printf(
        "Decimal value of binary number "
        BINARY_NUM_T_FORMAT_SPECIFIER
        " is "
        "%d"
        "\n",
        binaryNumber,
        decimalValue);
}

int main() {
    const binary_num_t binaryNumber = getBinaryNumber();
    printBinaryNumberAsDecimal(binaryNumber);

    return EXIT_SUCCESS;
}
