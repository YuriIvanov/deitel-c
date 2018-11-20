#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    unsigned int aCount = 0;
    unsigned int bCount = 0;
    unsigned int cCount = 0;
    unsigned int dCount = 0;
    unsigned int fCount = 0;

    puts("Enter the letter grades." );
    puts("Enter the EOF character to end input." );
    int grade;

    while ((grade = getchar()) != EOF) {
        bool isCorrectValueEntered = false;

        if (grade == 'A' || grade == 'a') {
            ++aCount;
            isCorrectValueEntered = true;
        }
        if (grade == 'B' || grade == 'b') {
            ++bCount;
            isCorrectValueEntered = true;
        }
        if (grade == 'C' || grade == 'c') {
            ++cCount;
            isCorrectValueEntered = true;
        }
        if (grade == 'D' || grade == 'd') {
            ++dCount;
            isCorrectValueEntered = true;
        }
        if (grade == 'F' || grade == 'f') {
            ++fCount;
            isCorrectValueEntered = true;
        }
        if (grade == '\n' || grade == '\t' || grade == ' ') {
            isCorrectValueEntered = true;
        }

        if (!isCorrectValueEntered) {
            fflush(stdin);
            printf("%s", "Incorrect letter grade entered.");
            puts(" Enter a new grade.");
        }
    }

    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", aCount);
    printf("B: %u\n", bCount);
    printf("C: %u\n", cCount);
    printf("D: %u\n", dCount);
    printf("F: %u\n", fCount);
}

