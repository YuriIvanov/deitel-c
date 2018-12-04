#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ROWS 9
#define DIAMOND_SYMBOL '*'

static void printDiamondRow(const int width, const int numberOfSymbols) {
    // Width and number of symbols should be an odd numbers.
    // Otherwise we can't print right diamond.
    // Of course width and number of symbols can't be negative.
    if ((width % 2 <= 0) || (numberOfSymbols % 2 <= 0)) {
        puts("Diamond row width and number of symbols should be positive odd numbers.");
        exit(EXIT_FAILURE);
    }

    // First we need to find number of blanks before and after rows.
    const int numberOfBlanks = width - numberOfSymbols;
    if (numberOfBlanks < 0) {
        puts("Number of symbols in row can't be greater than row width.");
        exit(EXIT_FAILURE);
    }

    // Print blanks before.
    for (int blanksBefore = numberOfBlanks / 2; blanksBefore > 0; --blanksBefore) {
        printf("%c", ' ');
    }

    // Print symbols.
    for (int symbols = numberOfSymbols; symbols > 0; -- symbols) {
        printf("%c", '*');
    }

    // Print blanks after.
    for (int blanksAfter = numberOfBlanks / 2; blanksAfter > 0; --blanksAfter) {
        printf("%c", ' ');
    }

    puts("");
}

static void printDiamond(const int numberOfRows) {
    // Number of rows should be positive odd number.
    if (numberOfRows % 2 <= 0) {
        puts("Number of rows in diamond should be positive odd number.");
        exit(EXIT_FAILURE);
    }

    // Print top half of diamond.
    int numberOfSymbols = 1;

    for (int row = 0; row < numberOfRows / 2; ++row) {
        printDiamondRow(numberOfRows, numberOfSymbols);
        numberOfSymbols += 2;
    }

    // Print bottom half of diamond.
    for (int row = numberOfRows; row > numberOfRows / 2; --row) {
        printDiamondRow(numberOfRows, numberOfSymbols);
        numberOfSymbols -= 2;
    }
}

int main(void) {
    printDiamond(NUMBER_OF_ROWS);

    return EXIT_SUCCESS;
}
