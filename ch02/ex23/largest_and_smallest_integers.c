#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;

    printf("%s", "Enter three different integers: ");
    scanf("%d%d%d", &a, &b, &c);

    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }

    int largets = a;
    if (b > largets) {
        largets = b;
    }
    if (c > largets) {
        largets = c;
    }

    printf("Smallest number is: %d\nLargest number is: %d\n",smallest,largets);

    return EXIT_SUCCESS;
}
