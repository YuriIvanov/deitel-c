#include <stdlib.h>
#include <stdio.h>

#define GRADE_A_WEIGHT 5
#define GRADE_B_WEIGHT 4
#define GRADE_C_WEIGHT 3
#define GRADE_D_WEIGHT 2
#define GRADE_F_WEIGHT 1

static char weightToGrade(const int gradeWeight) {
    switch (gradeWeight) {
        case GRADE_A_WEIGHT:
            return 'A';
        case GRADE_B_WEIGHT:
            return 'B';
        case GRADE_C_WEIGHT:
            return 'C';
        case GRADE_D_WEIGHT:
            return 'D';
        case GRADE_F_WEIGHT:
            return 'F';
        default:
            printf(
                "Incorrect grade weight: %d\n"
                "Shutting down...",
                gradeWeight);
            exit(EXIT_FAILURE);
    }
}

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
        switch (grade) {
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                printf("%s", "Incorrect letter grade entered.");
                puts(" Enter a new grade.");
                break;
        }
    }

    const unsigned int numberOfGrades = aCount + bCount + cCount + dCount + fCount;
    const unsigned int gradesWeight =
        aCount * GRADE_A_WEIGHT +
        bCount * GRADE_B_WEIGHT +
        cCount * GRADE_C_WEIGHT +
        dCount * GRADE_D_WEIGHT +
        fCount * GRADE_F_WEIGHT;

    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", aCount);
    printf("B: %u\n", bCount);
    printf("C: %u\n", cCount);
    printf("D: %u\n", dCount);
    printf("F: %u\n", fCount);
    printf("Average grade for class is: %c\n", weightToGrade(gradesWeight / numberOfGrades));
}
