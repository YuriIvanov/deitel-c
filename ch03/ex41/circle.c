#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getCircleRadius(void) {
    float radius = 0.0;

    printf("%s", "Enter circle radius: ");
    scanf("%f", &radius);

    return radius;
}

float calculateCircleDiameter(const float radius) {
    return 2 * radius;
}

float calculateCircleCircumference(const float radius) {
    return 2 * M_PI * radius;
}

float calculateCircleArea(const float radius) {
    return M_PI * (radius * radius);
}

int main(void) {
    const float circleRadius = getCircleRadius();
    const float circleDiameter = calculateCircleDiameter(circleRadius);
    const float circleCircumference = calculateCircleCircumference(circleRadius);
    const float circleArea = calculateCircleArea(circleRadius);

    printf(
        "Circle diameter is: %.2f\n"
        "Circle circumference is: %.2f\n"
        "Circle area is: %.2f\n",
        circleDiameter,
        circleCircumference,
        circleArea);

    return EXIT_SUCCESS;
}
