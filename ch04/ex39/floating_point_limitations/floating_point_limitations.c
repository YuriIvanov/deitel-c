#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float money = 1000000.00f;
    money += 0.12f;

    printf("Your money: %.2f", money);

    return EXIT_SUCCESS;
}
