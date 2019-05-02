#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static double triangleArea(const double firstTriangleSide,
                           const double secondTriangleSide,
                           const double thirdTriangleSide) {
    // We'll use Heron's formula.
    const double p = (firstTriangleSide + secondTriangleSide + thirdTriangleSide) / 2;
    return sqrt(p * (p - firstTriangleSide) * (p - secondTriangleSide) * (p - thirdTriangleSide));
}

static double getTriangleSide(const char *side) {
    double triangleSide = -1.0;

    do {
        printf("Enter %s triangle side length: ", side);

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

static bool isTriangleSides(const double firstTriangleSide,
                            const double secondTriangleSide,
                            const double thirdTriangleSide) {
    return (
               (firstTriangleSide + secondTriangleSide > thirdTriangleSide) &&
               (secondTriangleSide + thirdTriangleSide > firstTriangleSide) &&
               (firstTriangleSide + thirdTriangleSide > secondTriangleSide)
           );
}

static void calculateTriangle(void) {
    while (true) {
        const double firstTriangleSide = getTriangleSide("first");
        const double secondTriangleSide = getTriangleSide("second");
        const double thirdTriangleSide = getTriangleSide("third");

        const bool isSidesOfTriangle = isTriangleSides(firstTriangleSide, secondTriangleSide, thirdTriangleSide);
        if (isSidesOfTriangle) {
            const double areaOfTriangle = triangleArea(firstTriangleSide, secondTriangleSide, thirdTriangleSide);
            printf(
                "\nTriangle sides: %.2lf, %.2lf, %.2lf."
                "\nTriangle area: %.2lf.\n\n",
                firstTriangleSide, secondTriangleSide, thirdTriangleSide,
                areaOfTriangle
            );
            break;
        } else {
            puts("Side lengths you've entered are not sides of triangle. Try again.");
        }
    }
}

static bool calculateAnotherTriangle(void) {
    int answer = -1;

    do {
        printf("%s", "Enter 1 to calculate another triangle or 0 to exit: ");

        const int scanfResult = scanf("%d", &answer);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (answer != 0 && answer != 1) {
            puts("You've entered incorrect answer. Try again.");
        }
    } while (answer != 0 && answer != 1);

    return answer;
}

int main(void) {
    while (true) {
        calculateTriangle();
        if (!calculateAnotherTriangle()) {
            break;
        }
        puts("");
    }
    return EXIT_SUCCESS;
}
