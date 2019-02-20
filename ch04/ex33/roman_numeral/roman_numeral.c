#include <stdio.h>
#include <stdlib.h>

// See https://www.rapidtables.com/convert/number/how-number-to-roman-numerals.html.
static const int DECIMAL_TABLE[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
static const char *ROMAN_SYMBOL_TABLE[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

static void decimalToRomanNumeral(const int number) {
    if (number <= 0) {
        puts("Romans had no zero of negative numbers.");
        exit(-1);
    }

    int decimal = number;
    printf("%-7d ", decimal);

    int i = 0;
    while(decimal) {
        while(decimal / DECIMAL_TABLE[i]) {
            printf("%s", ROMAN_SYMBOL_TABLE[i]);
            decimal -= DECIMAL_TABLE[i];
        }
        i++;
    }
    puts("");
}

int main(void) {
    printf("%-7s %-5s\n", "Decimal", "Roman");
    for (int decimal = 1; decimal <= 100; ++decimal) {
        decimalToRomanNumeral(decimal);
    }

    return EXIT_SUCCESS;
}
