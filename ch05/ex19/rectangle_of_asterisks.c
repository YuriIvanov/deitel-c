#include <stdio.h>
#include <stdlib.h>

#define MIN_RECTAGLE_SIDE_LENGTH 2

#define RECTANGLE_CHAR '*'

static int getRectangleSide(const char *side) {
    int rectangleSide = 0;

    do {
        printf("Enter %s rectangle side length: ", side);

        const int scanfResult = scanf("%d", &rectangleSide);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (rectangleSide < MIN_RECTAGLE_SIDE_LENGTH) {
            puts("You've entered incorrect rectangle side length. Try again.");
        }
    } while (rectangleSide < MIN_RECTAGLE_SIDE_LENGTH);

    return rectangleSide;
}

static void printRectangle(const int side1, const int side2) {
    for (int s1 = 0; s1 < side1; ++s1) {
        for (int s2 = 0; s2 < side2; ++s2) {
            printf("%c ", RECTANGLE_CHAR);
        }
        puts("");
    }
}

int main(void) {
    const int side1 = getRectangleSide("first");
    const int side2 = getRectangleSide("second");

    printRectangle(side1, side2);

    return EXIT_SUCCESS;
}
