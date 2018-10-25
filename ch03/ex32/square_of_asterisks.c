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

void drawSquare(const int squareSide) {
    int rows = squareSide;
    while (rows > 0) {
        int columns = squareSide;
        while (columns > 0) {
            printf("%s", "*");
            --columns;
        }

        printf("%s", "\n");
        --rows;
    }
}

int main(void) {
    const int squareSide = getSideOfSquare();
    drawSquare(squareSide);

    return EXIT_SUCCESS;
}
