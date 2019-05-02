#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double getTriangleSide(void) {
    double triangleSide = -1.0;

    do {
        printf("%s", "Enter triangle side length: ");

        const int scanfResult = scanf("%lf", &triangleSide);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (triangleSide <= 0) {
            puts("You've entered incorrect triangle side length. Try again.");
        }
    } while (triangleSide <= 0);

    return triangleSide;
}

static double hypotenuse(const double side1, const double side2) {
    return sqrt((side1 * side1) + (side2 * side2));
}

int main(void) {
    const double triangleSide1 = getTriangleSide();
    const double triangleSide2 = getTriangleSide();
    const double triangleHypotenuse = hypotenuse(triangleSide1, triangleSide2);

    printf(
        "\nSide1 = %.2lf; Side2 = %.2lf; Hypotenuse = %.2lf.",
        triangleSide1,
        triangleSide2,
        triangleHypotenuse);

    return EXIT_SUCCESS;
}
