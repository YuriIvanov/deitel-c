#include <stdio.h>
#include <stdlib.h>


#define WEEKLY_HOURS 40
#define OVERPAY_RATE 1.5

int getHoursWorked(void) {
    int hoursWorked = 0;

    printf("%s", "Enter # or hours worked (-1 to end): ");
    scanf("%d", &hoursWorked);

    return hoursWorked;
}

float getHourlyRate(void) {
    float hourlyRate = 0.0;

    printf("%s", "Enter hourly rate of the worker ($00.00): ");
    scanf("%f", &hourlyRate);

    return hourlyRate;
}

float calculateSalary(const int hoursWorked, const float hourlyRate) {
    int overpayHours = hoursWorked - WEEKLY_HOURS;
    if (overpayHours < 0) {
        overpayHours = 0;
    }

    int staightHours = hoursWorked - overpayHours;

    return (staightHours * hourlyRate) + (overpayHours * (hourlyRate * OVERPAY_RATE));
}

void printSalary(const float salary) {
    printf("Salary is $%.2f\n\n", salary);
}

int main() {
    int hoursWorked = getHoursWorked();
    while (hoursWorked != -1) {
        const float hourlyRate = getHourlyRate();

        const float salary = calculateSalary(hoursWorked, hourlyRate);
        printSalary(salary);

        hoursWorked = getHoursWorked();
    }

    return EXIT_SUCCESS;
}
