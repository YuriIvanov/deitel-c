#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 0;
    int b = 0;

    printf("%s", "Enter two integer numbers: ");
    scanf("%d%d", &a, &b);

    if (!(b % a)) {
        printf("%d is multiple of %d\n", b, a);
    } else {
        printf("%d is not multiple of %d\n", b, a);
    }

    return EXIT_SUCCESS;
}
