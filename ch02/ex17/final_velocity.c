#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int u = 0;
    int a = 0;
    int t = 0;

    printf("%s", "Enter initial velocity: ");
    scanf("%d", &u);

    printf("%s", "Enter initial acceleration: ");
    scanf("%d", &a);

    printf("%s", "Enter elapsed time: ");
    scanf("%d", &t);

    int v = u + (a * t);
    int s = (u * t) + (a * (t * t) * 0.5);

    printf("Final velocity is: %d\nDistance traversed is: %d\n", v, s);

    return EXIT_SUCCESS;
}
