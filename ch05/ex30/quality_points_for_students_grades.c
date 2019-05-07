#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXIT_VALUE -1

static int getStudentAverage() {
    int studentAverage = EXIT_VALUE - 1;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("Enter student's average (0 to 100, %d to exit): ", EXIT_VALUE);
        const int scanfResult = scanf("%d", &studentAverage);

        isUserInputValid =
            (scanfResult == 1 &&
             studentAverage >= 0 && studentAverage <= 100) ||
            studentAverage == EXIT_VALUE;

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect student's average. Try again.");
        }
    }

    return studentAverage;
}

static int toQualityPoints(const int studentAverage) {
    if (studentAverage >= 90 && studentAverage <= 100) {
        return 4;
    } else if (studentAverage >= 80 && studentAverage <= 89) {
        return 3;
    } else if (studentAverage >= 70 && studentAverage <= 79) {
        return 2;
    } else if (studentAverage >= 60 && studentAverage <= 69) {
        return 1;
    } else if (studentAverage >= 0 && studentAverage <= 59) {
        return 0;
    }

    puts("You've entered invalid student's average. Shutting down...");
    exit(EXIT_FAILURE);
}

int main(void) {
    while (true) {
        const int studentAverage = getStudentAverage();

        if (studentAverage == EXIT_VALUE) {
            break;
        }

        printf(
            "Student grade for %d points is: %d\n\n",
            studentAverage,
            toQualityPoints(studentAverage)
        );
    }

    return EXIT_SUCCESS;
}
