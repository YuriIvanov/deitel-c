#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getWeightInKillograms(void) {
    double weight = 0.0;

    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);

    return weight;
}

double getHeightInMeters(void) {
    double height = 0.0;

    printf("Enter your height in meters: ");
    scanf("%lf", &height);

    return height;
}

double calculateBmi(const double weightInKillograms, const double heightInMeters) {
    return weightInKillograms / (heightInMeters * heightInMeters);
}

void printBmi(const double bmi) {
    printf("\nYour BMI is: %.2lf\n", bmi);
    puts(
        "BMI VALUES\n"
        "Underweight: less than 18.5\n"
        "Normal:      between 18.5 and 24.9\n"
        "Overweight:  between 25 and 29.9\n"
        "Obese:       30 or greater");
}

int main(void) {
    double weight = getWeightInKillograms();
    double height = getHeightInMeters();
    double bmi = calculateBmi(weight, height);

    printBmi(bmi);

    return EXIT_SUCCESS;
}
