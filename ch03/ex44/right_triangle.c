#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getTriangleSide(void) {
    int side = -1;
    while (side <= 0) {
        printf("%s", "Enter triangle side: ");
        scanf("%d", &side);

        if (side <= 0) {
            puts("You've entered incorrect side size. Please, try again.");
        }
    }

    return side;
}

bool isRightTriangle(const int firstSide, const int secondSide, const int thirdSide) {
    if (firstSide == secondSide && secondSide == thirdSide) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    const int firstTriangleSide = getTriangleSide();
    const int secondTriangleSide = getTriangleSide();
    const int thirdTriangleSide = getTriangleSide();

    if (isRightTriangle(firstTriangleSide, secondTriangleSide, thirdTriangleSide)) {
        puts("Entered sides represents right triangle.");
    } else {
        puts("Entered sides doesn't represents right triangle.");
    }

    return EXIT_SUCCESS;
}
