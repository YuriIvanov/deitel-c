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

bool isTriangle(const int firstSide, const int secondSide, const int thirdSide) {
    if (firstSide <= 0 || secondSide <= 0 || thirdSide <= 0) {
        return false;
    }

    // Axiom of triangle inequality.
    const bool isFirstSideCorrect = (secondSide + thirdSide) >= firstSide;
    const bool isSecondSideCorrect = (firstSide + thirdSide) >= secondSide;
    const bool isThirdSideCorrect =  (firstSide + secondSide) >= thirdSide;

    if (isFirstSideCorrect && isSecondSideCorrect && isThirdSideCorrect) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    const int firstTriangleSide = getTriangleSide();
    const int secondTriangleSide = getTriangleSide();
    const int thirdTriangleSide = getTriangleSide();

    if (isTriangle(firstTriangleSide, secondTriangleSide, thirdTriangleSide)) {
        puts("Entered sides represents triangle.");
    } else {
        puts("Entered sides doesn't represents triangle.");
    }

    return EXIT_SUCCESS;
}
