#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int userSeconds = 0;
    printf("%s", "Enter total time elapsed in seconds: ");
    scanf("%d", &userSeconds);

    int hours = userSeconds / 60 / 60;
    int minutes = (userSeconds / 60) % 60;
    int seconds = userSeconds % 60;

    printf("The time elapsed is: %dh:%dm:%ds", hours, minutes, seconds);

    return EXIT_SUCCESS;
}
