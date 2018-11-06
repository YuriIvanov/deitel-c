#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mem.h>

#define MINIMAL_YEAR 1900

#define MINIMAL_TARGET_HEART_RATE_PERCENTAGE 0.5
#define MAXIMUM_TARGET_HEART_RATE_PERCENTAGE 0.85

enum months_e {
    MONTH_NONE = 0,
    MONTH_JANUARY = 1,
    MONTH_FEBRUARY = 2,
    MONTH_MARCH = 3,
    MONTH_APRIL = 4,
    MONTH_MAY = 5,
    MONTH_JUNE = 6,
    MONTH_JULY = 7,
    MONTH_AUGUST = 8,
    MONTH_SEPTEMBER = 9,
    MONTH_OCTOBER = 10,
    MONTH_NOVEMBER = 11,
    MONTH_DECEMBER = 12
};

struct date_t {
    int year;
    int month; // 1-12
    int dayOfMonth; // 1-31
};

struct target_heart_rate_t {
    int minimal;
    int maximum;
};

// Days from January to December.
// First 0 value is for simplified work with months index (1 - 12).
static const int daysInMonth[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/** \brief Determines whether specified year is leap of not.
 *
 * \param year const int Year to check.
 * \return bool True if year is leap, false otherwise.
 */
static bool isLeapYear(const int year) {
    if (((year % 4 == 0) &&(year % 100!= 0)) || (year%400 == 0)) {
        return true;
    } else {
        return false;
    }
}

/** \brief Get number of days for specified month in specified year.
 *
 * \param month const enummonths_e Month to get days from.
 * \param year const int Year which month we get days from.
 * \return int Number of days in month.
 */
static int daysInMonthInCurrentYear(const enum months_e month, const int year) {
    // Special case for leap year February.
    if (month == MONTH_FEBRUARY) {
        if (isLeapYear(year)) {
            return daysInMonth[month] + 1;
        }
    }

    return daysInMonth[month];
}


/** \brief Determine whether specified day in correct for specified month and year.
 *
 * \param day const int Day to check.
 * \param month const enummonths_e Month which day we check.
 * \param year const int Year which day we check.
 * \return bool True if day is correct, false otherwise.
 */
static bool isCorrectDayInMonthAndYear(const int day, const enum months_e month, const int year) {
    const int daysInMonth = daysInMonthInCurrentYear(month, year);

    if (day <= 0 || day > daysInMonth) {
        return false;
    } else {
        return true;
    }
}

/** \brief Get year from user.
 *
 * \return int Year.
 */
static int getYear(void) {
    int year = MINIMAL_YEAR - 1;

    while (year < MINIMAL_YEAR) {
        printf("Enter year (not less than %d): ", MINIMAL_YEAR);
        scanf("%d", &year);

        if (year < MINIMAL_YEAR) {
            puts("You've entered wrong year. Try again.");
        }
    }

    return year;
}

/** \brief Get month from user in form of index from 1 to 12. Use it with daysInMonth array.
 *
 * \return int Month of year.
 */
static int getMonthOfYear(void) {
    int month = -1;

    while (month < 1 || month > 12) {
        printf("%s", "Enter month (1-12): ");
        scanf("%d", &month);

        if (month < 1 || month > 12) {
            puts("You've entered wrong month. Try again.");
        }
    }

    return month;
}

/** \brief Get day of month from user.
 *
 * \param month const enummonths_e Month which day we want to get.
 * \param year const int Year which day we want to get.
 * \return int Day of month.
 *
 */
static int getDayOfMonthAndYear(const enum months_e month, const int year) {
    int day = -1;

    while (!isCorrectDayInMonthAndYear(day, month, year)) {
        printf("%s", "Enter day of month: ");
        scanf("%d", &day);

        if (!isCorrectDayInMonthAndYear(day, month, year)) {
            puts("You've entered wrong day. Try again.");
        }
    }

    return day;
}

/** \brief Get date from user.
 *
 * \param date struct date_t* Stores date received from user.
 * \return void
 */
static void getDate(struct date_t* date) {
    const int year = getYear();
    const int month = getMonthOfYear();
    const int day = getDayOfMonthAndYear(month, year);

    date->year = year;
    date->month = month;
    date->dayOfMonth = day;
}

/** \brief Calculates person age in full years.
 *
 * \param birthday const struct date_t* Person birthday.
 * \param currentDate const struct date_t* Current date.
 * \return int Age in full years. Negative number means that birthday or current date is incorrect.
 */
static int calculateAge(const struct date_t* birthday, const struct date_t* currentDate) {
    // We may also check that birthday is less than current day.
    // But let's omit this for simplicity of the whole program.
    int years = currentDate->year - birthday->year;

    const int monthDiff = currentDate->month - birthday->month;
    if (monthDiff < 0) {
        // We didn't reach birthday in this year yet.
        --years;
    } else if (monthDiff == 0) {
        // We have to check days now in a similar way we've checked months.
        const int daysDiff = currentDate->dayOfMonth - birthday->dayOfMonth;
        if (daysDiff < 0) {
            // We didn't reach birthday in this month yet.
            --years;
        }
    }
    return years;
}

/** \brief Calculates person maximum heart rate.
 *
 * \param personAgeInYears const int Person's age in years.
 * \return int Calculated maximum heart rate.
 */
static int calculateMaximumHeartRate(const int personAgeInYears) {
    return 220 - personAgeInYears;
}

/** \brief Calculates minimum and maximum target heart rate.
 *
 * \param maximumHeartRate const int Person's maximum heart rate.
 * \param targetHeartRate struct target_heart_rate_t* Stores results of calculation.
 * \return void
 */
static void calculateTargetHeartRate(const int maximumHeartRate,
                                     struct target_heart_rate_t* targetHeartRate) {
    targetHeartRate->minimal = maximumHeartRate * MINIMAL_TARGET_HEART_RATE_PERCENTAGE;
    targetHeartRate->maximum = maximumHeartRate * MAXIMUM_TARGET_HEART_RATE_PERCENTAGE;
}

/** \brief Print person's heart rate report
 *
 * \param personAgeInYears const int Person's age.
 * \param maximumHeartRate const int Person's maximum heart rate.
 * \param targetHeartRate const struct target_heart_rate_t* Person's minimum and maximum target heart rates.
 * \return void
 */
static void printHeartRateReport(const int personAgeInYears,
                                 const int maximumHeartRate,
                                 const struct target_heart_rate_t* targetHeartRate) {
    printf(
        "For your age (%d) heart rates are following:\n"
        "Maximum heart rate: %d\n"
        "Minimal target heart rate: %d\n"
        "Maximum target heart rate: %d\n",
        personAgeInYears,
        maximumHeartRate,
        targetHeartRate->minimal,
        targetHeartRate->maximum);
}

int main(void) {
    struct date_t birthday = {0};
    struct date_t currentDate = {0};

    int personAgeInYears = -1;
    do {
        puts("Enter your birth date.");
        getDate(&birthday);

        puts("Enter current date.");
        getDate(&currentDate);

        personAgeInYears = calculateAge(&birthday, &currentDate);
        if (personAgeInYears < 0) {
            puts("Are you from the future? :) Try to enter correct dates.");
        }
    } while (personAgeInYears < 0);

    const int maximumHeartRate = calculateMaximumHeartRate(personAgeInYears);

    struct target_heart_rate_t targetHeartRate = {0};
    calculateTargetHeartRate(maximumHeartRate, &targetHeartRate);

    printHeartRateReport(personAgeInYears, maximumHeartRate, &targetHeartRate);

    return EXIT_SUCCESS;
}
