#include <stdio.h>
#include <stdlib.h>

int getMaxCounterValue(void) {
    int maxCounterValue = 0;

    printf("%s", "Enter max counter value: ");
    scanf("%d", &maxCounterValue);

    return maxCounterValue;
}

void showPreincrementCycle(const int maxCounterValue) {
    int counter = 0;

    printf("Cycling from %d up to but not including %d using preincrement in cycle header:\n", counter, maxCounterValue);
    while(++counter < maxCounterValue) {
        printf("Counter value: %d\n", counter);
    }
    puts("");
}

void showPostincrementCycle(const int maxCounterValue) {
    int counter = 0;

    printf("Cycling from %d up to but not including %d using postincrement cycle header:\n", counter, maxCounterValue);
    while(counter++ < maxCounterValue) {
        printf("Counter value: %d\n", counter);
    }
    puts("");
}

int main() {
    const int maxCounterValue = getMaxCounterValue();

    showPreincrementCycle(maxCounterValue);
    showPostincrementCycle(maxCounterValue);

    return EXIT_SUCCESS;
}
