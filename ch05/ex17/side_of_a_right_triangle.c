#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static int getTriangleSide(const char *side) {
    int triangleSide = 0;

    do {
        printf("Enter %s triangle side length: ", side);

        const int scanfResult = scanf("%d", &triangleSide);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (triangleSide <= 0) {
            puts("You've entered incorrect triangle side length. Try again.");
        }
    } while (triangleSide <= 0);

    return triangleSide;
}

static bool isTriangleSides(const int a,const int b,const int c) {
    return (
               (a + b > c) &&
               (b + c > a) &&
               (a + c > b)
           );
}

static bool isRightAngeledTriangle(const int a, const int b, const int c) {
    return (
               (a * a + b * b == c * c) ||
               (b * b + c * c == a * a) ||
               (a * a + c * a ==  b * b)
           );
}

static void calculateTriangle(void) {
    while (true) {
        const int firstTriangleSide = getTriangleSide("first");
        const int secondTriangleSide = getTriangleSide("second");
        const int thirdTriangleSide = getTriangleSide("third");

        const bool isSidesOfTriangle = isTriangleSides(firstTriangleSide, secondTriangleSide, thirdTriangleSide);
        if (isSidesOfTriangle) {
            const bool rightAngeledTriangle =
                isRightAngeledTriangle(firstTriangleSide, secondTriangleSide, thirdTriangleSide);
            printf(
                "\nTriangle sides: %d, %d, %d."
                "\nIs right-angeled triangle: %d.\n\n",
                firstTriangleSide, secondTriangleSide, thirdTriangleSide,
                rightAngeledTriangle
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
