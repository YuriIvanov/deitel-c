#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static int getTwelveHourClockHours(void) {
    int hours = -1;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", "Enter twelve hour clock hours (1-12): ");
        const int scanfResult = scanf("%d", &hours);

        isUserInputValid =
            scanfResult == 1 &&
            hours >= 1 && hours <= 12;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect hours. Try again.");
        }
    };

    return hours;
}

static int getMinutes(void) {
    int minutes = -1;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", "Enter minutes (0-59): ");
        const int scanfResult = scanf("%d", &minutes);

        isUserInputValid =
            scanfResult == 1 &&
            minutes >= 0 && minutes <= 59;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect minutes. Try again.");
        }
    };

    return minutes;
}

static int getSeconds(void) {
    int seconds = -1;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", "Enter seconds (0-59): ");
        const int scanfResult = scanf("%d", &seconds);

        isUserInputValid =
            scanfResult == 1 &&
            seconds >= 0 && seconds <= 59;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect seconds. Try again.");
        }
    };

    return seconds;
}

static long calculateSecondsSinceLastTwelve(
    const int twelveHoursClockHours,
    const int minutes,
    const int seconds) {
    int hours = (twelveHoursClockHours == 12) ? 0 : twelveHoursClockHours;

    return hours * 3600 + minutes * 60 + seconds;
}

static long getSecondsSinceLastTwelve(void) {
    const int twelveHoursClockHours = getTwelveHourClockHours();
    const int minutes = getMinutes();
    const int seconds = getSeconds();

    return calculateSecondsSinceLastTwelve(twelveHoursClockHours, minutes, seconds);
}

int main(void) {
    const long firstTime = getSecondsSinceLastTwelve();

    puts("");

    const long secondTime = getSecondsSinceLastTwelve();

    printf("\nAmount of time between two entered times is: %ld.\n", labs(firstTime - secondTime));

    return EXIT_SUCCESS;
}
