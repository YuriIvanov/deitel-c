#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;

    printf("%s", "Enter three different integers: ");
    scanf("%d%d%d", &a, &b, &c);

    int sum = a + b + c;
    int average = sum / 3;
    int product = a * b * c;

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

    printf(
        "Sum is: %d\nAverage is: %d\nProduct is: %d\nSmallest number is: %d\nLargest number is: %d\n",
        sum,
        average,
        product,
        smallest,
        largets);

    return EXIT_SUCCESS;
}
