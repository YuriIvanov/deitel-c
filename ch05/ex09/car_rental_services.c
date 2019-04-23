#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HOURS_PER_DAY 24
#define RENT_HOURS_WITHOUT_ADDITIONAL_CHARGES 8

#define MINIMUM_FEE 25.00
#define MAXIMUM_DAILY_CHARGE 50.0

#define SERVICE_TAX_PER_HOUR 0.5
#define ADDITIONAL_CHARGE_PER_HOUR 5.0

static double calculateCharges(const int rentHours) {
    if (rentHours <= 0) {
        puts("Rent hours should be greater than zero.");
        exit(EXIT_FAILURE);
    }

    // We always take service tax no matter how many rent hours customer has.
    double charge = rentHours * SERVICE_TAX_PER_HOUR;

    if (rentHours >= HOURS_PER_DAY) {
        // Calculate charge on daily basis.
        int days = rentHours / HOURS_PER_DAY;
        if (rentHours % HOURS_PER_DAY > 0) {
            days += 1;
        }
        charge += days * MAXIMUM_DAILY_CHARGE;
    } else {
        charge += MINIMUM_FEE;

        const int hours_with_additional_charge = rentHours - RENT_HOURS_WITHOUT_ADDITIONAL_CHARGES;
        if (hours_with_additional_charge > 0) {
            charge += hours_with_additional_charge * ADDITIONAL_CHARGE_PER_HOUR;
        }
    }

    return charge;
}

static int getRentHours(const int customerNumber) {
    int rentHours = -1;

    do {
        printf("Enter rent hours for customer %d (max 72 hours): ", customerNumber);

        const int scanfResult = scanf("%d", &rentHours);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (rentHours <= 0 || rentHours > 72) {
            puts("You've entered incorrect rent hours. Try again.");
        }
    } while (rentHours <= 0 || rentHours > 72);

    return rentHours;
}

int main(void) {
    const int customerOneRentHours = getRentHours(1);
    const int customerTwoRentHours = getRentHours(2);
    const int customerThreeRentHours = getRentHours(3);
    const int totalRentHours = customerOneRentHours + customerTwoRentHours + customerThreeRentHours;

    const double customerOneCharge = calculateCharges(customerOneRentHours);
    const double customerTwoCharge = calculateCharges(customerTwoRentHours);
    const double customerThreeCharge = calculateCharges(customerThreeRentHours);
    const double totalCharge = customerOneCharge + customerTwoCharge + customerThreeCharge;

    printf("\n%-9s%-11s%s\n", "Car", "Hours", "Charge");
    printf("%-10d%-4d%12.2lf\n", 1, customerOneRentHours, customerOneCharge);
    printf("%-10d%-4d%12.2lf\n", 2, customerTwoRentHours, customerTwoCharge);
    printf("%-10d%-4d%12.2lf\n", 3, customerThreeRentHours, customerThreeCharge);
    printf("%-10s%-4d%12.2lf\n", "TOTAL", totalRentHours, totalCharge);

    return EXIT_SUCCESS;
}
