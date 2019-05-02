#include <stdio.h>
#include <stdlib.h>

#define MIN_RECTAGLE_SIDE_LENGTH 2

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

static int getFillCharacter(void) {
    char fillCharacter = '#';
    int scanfResult = 0;

    fflush(stdin);
    do {
        printf("%s", "Enter rectangle fill character: ");

        scanfResult = scanf("%c", &fillCharacter);
        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect rectangle fill character. Try again.");
        }
    } while (scanfResult != 1);

    return fillCharacter;
}

static void printRectangle(const int side1,
                           const int side2,
                           const char fillCharacter) {
    for (int s1 = 0; s1 < side1; ++s1) {
        for (int s2 = 0; s2 < side2; ++s2) {
            printf("%c ", fillCharacter);
        }
        puts("");
    }
}

int main(void) {
    const int side1 = getRectangleSide("first");
    const int side2 = getRectangleSide("second");
    const char fillCharacter = getFillCharacter();

    printRectangle(side1, side2, fillCharacter);

    return EXIT_SUCCESS;
}
