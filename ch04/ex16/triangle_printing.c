#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 10

static void printAsterisks(const int numberOfAsterisks) {
    int asterisks = numberOfAsterisks;
    while (asterisks > 0) {
        printf("%s", "*");
        --asterisks;
    }
}

static void printBlanks(const int numberOfBlanks) {
    int blanks = numberOfBlanks;
    while (blanks > 0) {
        printf("%s", " ");
        --blanks;
    }
}

int main(void) {
    // Triangle A.
    for (int asterisks = 1; asterisks <= LINE_LENGTH; ++asterisks) {
        printAsterisks(asterisks);
        printBlanks(asterisks - LINE_LENGTH);
        puts("");
    }

    puts("");

    // Triangle B.
    for (int asterisks = LINE_LENGTH; asterisks >= 0; --asterisks) {
        printAsterisks(asterisks);
        printBlanks(LINE_LENGTH - asterisks);
        puts("");
    }

    puts("");

       // Triangle C.
    for (int asterisks = LINE_LENGTH; asterisks >= 0; --asterisks) {
        printBlanks(LINE_LENGTH - asterisks);
        printAsterisks(asterisks);
        puts("");
    }

    // Triangle D.
    for (int asterisks = 1; asterisks <= LINE_LENGTH; ++asterisks) {
        printBlanks(LINE_LENGTH - asterisks);
        printAsterisks(asterisks);
        puts("");
    }

    return EXIT_SUCCESS;
}
