#include <stdio.h>
#include <stdlib.h>

int getSideOfSquare(void) {
    int side = 0;

    while (side <= 0 || side > 20) {
        printf("%s", "Enter side of square (1-20): ");
        scanf("%d", &side);

        if (side <= 0 || side > 20) {
            puts("You've entered wrong side. Please, try again.");
        }
    }

    return side;
}

void printFullRow(const int numberOfColumns) {
    int columns = numberOfColumns;
    while (columns > 0) {
        printf("%s", "*");
        --columns;
    }
    printf("%s", "\n");
}

void printHollowRow(const int numberOfColumns) {
    // It is impossible to print hollow row with number of columns less than 3.
    if (numberOfColumns < 3) {
        printFullRow(numberOfColumns);
        return;
    }

    // Print first symbol.
    printf("%s", "*");

    // Print hollowed columns.
    // Number of columns minus first and last columns.
    int columns = numberOfColumns - 2;
    while (columns > 0) {
        printf("%s", " ");
        --columns;
    }

    // Print last symbol.
    printf("%s", "*\n");
}

void drawHollowSquare(const int squareSide) {
    // We need to print full first row and full last row.
    // All other rows will have hollow inside;

    // We can't print hollow square with side less than 3.
    if (squareSide < 3) {
        int rows = squareSide;
        while (rows > 0) {
            printFullRow(squareSide);
            --rows;
        }
        return;
    }

    // Print first row.
    printFullRow(squareSide);

    // Print hollowed rows.
    // Square side - first and last rows.
    int rows = squareSide - 2;
    while (rows > 0) {
        printHollowRow(squareSide);
        --rows;
    }
    // Print last row.
    printFullRow(squareSide);
}

int main(void) {
    const int squareSide = getSideOfSquare();
    drawHollowSquare(squareSide);

    return EXIT_SUCCESS;
}
