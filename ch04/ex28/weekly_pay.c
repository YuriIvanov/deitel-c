#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

// Hourly worker.
#define HOURS_IN_WEEK 168.0
#define STANDARD_WEEKLY_WORKING_HOURS 40
#define HOURLY_WORKER_OVERPAY_RATE 1.5

// Commission worker.
#define COMMISSION_WORKER_WEEKLY_RATE 250.0
#define COMMISSION_WORKER_SALES_BONUS_PERCENT 0.57

// Should be less than min value in pay_code_e enumeration.
#define EXIT_PAY_CODE PAY_CODE_INVALID

// Should be equal to (max pay_code_e enumeration value + 1).
#define SIZE_OF_SALARY_HANDLERS_TABLE (PAY_CODE_PIECE_WORKER + 1)

enum pay_code_e {
    PAY_CODE_INVALID = 0,
    PAY_CODE_MANAGER = 1,
    PAY_CODE_HOURLY_WORKER = 2,
    PAY_CODE_COMMISSION_WORKER = 3,
    PAY_CODE_PIECE_WORKER = 4
};

typedef void (*salary_handler_t)(void);

static void unreachableSalaryHandler(void) {
    puts(
        "Unreachable payment handler.\n"
        "Check code correctness.\n"
        "Shutting down...");
    exit(EXIT_FAILURE);
}

static void printSalary(const char *whose, const double salary) {
    printf("%s earned %.2lf $ this week.\n\n", whose, salary);
}

static double getManagerWeeklySalary(void) {
    double weeklySalary = -1.0;

    do {
        printf("%s", "Enter Manager's weekly salary: ");

        const int scanfResult = scanf("%lf", &weeklySalary);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (weeklySalary < 0.0) {
            puts("You've entered incorrect salary. Try again.");
        }
    } while (weeklySalary < 0.0);

    return weeklySalary;
}

static void handleManagerSalary(void) {
    const double salary = getManagerWeeklySalary();
    printSalary("Manager", salary);
}

static double getHoursWorked(void) {
    double hoursWorked = -1.0;

    do {
        printf("%s", "Enter the number of hours worked by the employee this week: ");

        const int scanfResult = scanf("%lf", &hoursWorked);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (hoursWorked < 0.0 || hoursWorked > HOURS_IN_WEEK) {
            puts("You've entered incorrect number of hours. Try again.");
        }
    } while (hoursWorked < 0.0 || hoursWorked > HOURS_IN_WEEK);

    return hoursWorked;
}

static double getHourlyRate(void) {
    double hourlyRate = -1.0;

    do {
        printf("%s", "Enter hourly rate: ");

        const int scanfResult = scanf("%lf", &hourlyRate);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (hourlyRate < 0.0) {
            puts("You've entered incorrect hourly rate. Try again.");
        }
    } while (hourlyRate < 0.0);

    return hourlyRate;
}

static double calculateHourlyWorkerSalary(const double hoursWorked, const double hourlyRate) {
    double overpayHours = hoursWorked - STANDARD_WEEKLY_WORKING_HOURS;
    if (overpayHours < 0) {
        overpayHours = 0.0;
    }

    const double straight  = hoursWorked - overpayHours;

    return (straight * hourlyRate) + (overpayHours * (hourlyRate * HOURLY_WORKER_OVERPAY_RATE));
}

static void handleHourlyWorkerSalary(void) {
    const double hoursWorked = getHoursWorked();
    const double hourlyRate = getHourlyRate();
    const double salary = calculateHourlyWorkerSalary(hoursWorked, hourlyRate);

    printSalary("Hourly worker", salary);
}

static double getWeeklySalesAmount(void) {
    double weeklySales = -1.0;

    do {
        printf("%s", "Enter weekly sales amount: ");

        const int scanfResult = scanf("%lf", &weeklySales);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (weeklySales < 0.0) {
            puts("You've entered incorrect weekly sales amount. Try again.");
        }
    } while (weeklySales < 0.0);

    return weeklySales;
}

static double calculateCommissionWorkderSalary(const double weeklySalesAmount) {
    return COMMISSION_WORKER_WEEKLY_RATE +
           (weeklySalesAmount * COMMISSION_WORKER_SALES_BONUS_PERCENT);
}

static void handleCommissionWorkerSalary(void) {
    const double weeklySalesAmount = getWeeklySalesAmount();
    const double salary = calculateCommissionWorkderSalary(weeklySalesAmount);

    printSalary("Commission Worker", salary);
}

static int getNumberOfProducedItems(void) {
    int numberOfProducedItems = -1;

    do {
        printf("%s", "Enter number of items produced by pieceworker: ");

        const int scanfResult = scanf("%d", &numberOfProducedItems);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (numberOfProducedItems < 0) {
            puts("You've entered incorrect number of produced items. Try again.");
        }
    } while (numberOfProducedItems < 0);

    return numberOfProducedItems;
}

static double getItemPrice(void) {
    double itemPrice = -1.0;

    do {
        printf("%s", "Enter item price: ");

        const int scanfResult = scanf("%lf", &itemPrice);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (itemPrice < 0.0) {
            puts("You've entered incorrect item price. Try again.");
        }
    } while (itemPrice < 0.0);

    return itemPrice;
}

static double calculatePeiceWorkerSalary(const int numberOfProducedItems, const double itemPrice) {
    return numberOfProducedItems * itemPrice;
}

static void handlePieceWorkerSalary(void) {
    const int numberOfProducedItems = getNumberOfProducedItems();
    const double itemPrice = getItemPrice();
    const double salary = calculatePeiceWorkerSalary(numberOfProducedItems, itemPrice);

    printSalary("Pieceworker", salary);
}

static salary_handler_t salaryHandlers[SIZE_OF_SALARY_HANDLERS_TABLE] = {
    unreachableSalaryHandler,
    handleManagerSalary,
    handleHourlyWorkerSalary,
    handleCommissionWorkerSalary,
    handlePieceWorkerSalary
};

static void promptEnterThePayCode(void) {
    printf(
        "%s\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s",
        "Enter pay code.",
        "Manager", PAY_CODE_MANAGER,
        "Hourly Worker", PAY_CODE_HOURLY_WORKER,
        "Commission Worker", PAY_CODE_COMMISSION_WORKER,
        "Pieceworker", PAY_CODE_PIECE_WORKER,
        "To exit enter", EXIT_PAY_CODE,
        "Pay code: ");
}

static int getPayCode(void) {
    int payCode = EXIT_PAY_CODE - 1;

    do {
        promptEnterThePayCode();

        int scanfResult = scanf("%d", &payCode);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (payCode < EXIT_PAY_CODE || payCode > PAY_CODE_PIECE_WORKER) {
            puts("\nYou've entered incorrect pay code. Try again.");
        }
    } while (payCode < EXIT_PAY_CODE || payCode > PAY_CODE_PIECE_WORKER);

    puts("");

    return payCode;
}

int main(void) {
    while (true) {
        int payCode = getPayCode();
        if (payCode == EXIT_PAY_CODE) {
            break;
        }
        salaryHandlers[payCode]();
    }

    return EXIT_SUCCESS;
}
