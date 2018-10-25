// Fig. 3.10: fig03_10.c
// Analysis of examination results

#include <stdio.h>

int getResult(void) {
    int result = 0;

    while (result != 1 && result != 2) {
        printf("%s", "Enter result (1 = pass, 2 = fail ): ");
        scanf("%d", &result);

        if (result != 1 && result != 2) {
            puts("You've entered incorrect results. Please, try again.");
        }
    }

    return result;
}

void printResults(const unsigned int passes, const unsigned int failures) {
    printf("Passed %u\n", passes);
    printf("Failed %u\n", failures);

    if (passes > 8) {
        puts("Bonus to instructor!");
    }
}

int main(void) {
    unsigned int passes = 0;
    unsigned int failures = 0;
    unsigned int student = 1;

    while (student <= 10) {
        const int result = getResult();

        if (result == 1) {
            ++passes;
        } else {
            ++failures;
        }

        ++student;
    }

    printResults(passes, failures);
}
