#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    printf(
        "List of Pythagorean Triples for sides no more than 500.\n"
        "%-5s %-5s %s\n",
        "Side1",
        "Side2",
        "Hypotenuse");
    for (int side1 = 1; side1 <= 500; ++side1) {
        for (int side2 = 1; side2 <= 500; ++side2) {
            for (int hypotenuse = 1; hypotenuse <= 500; ++hypotenuse) {
                const bool isPythagoreanTriple =
                    (side1 * side1) + (side2 * side2) == (hypotenuse * hypotenuse);
                if (isPythagoreanTriple) {
                    printf("%-5d %-5d %d\n", side1, side2, hypotenuse);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
