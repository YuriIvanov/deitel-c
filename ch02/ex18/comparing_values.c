#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int highestRainfall = 0;
    int currentRainfall = 0;

    printf("%s", "Enter highest rainfall ever in one season: ");
    scanf("%d", &highestRainfall);

    printf("%s", "Enter rainfall for current year: ");
    scanf("%d", &currentRainfall);

    if (currentRainfall > highestRainfall) {
        puts("Rainfall in current year is the highest rainfall ever.");
        highestRainfall = currentRainfall;
    }

    return EXIT_SUCCESS;
}
