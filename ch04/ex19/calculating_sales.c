#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_PRODUCTS 5

static double prices[NUMBER_OF_PRODUCTS + 1] = {
    0.0, // Stub value for index 0.
    2.98,
    4.5,
    9.98,
    4.49,
    6.87,
};

static int getProductNumber(void) {
    int productNumber = -1;

    do {
        printf("Enter product number (1-%d, 0 - to stop): ", NUMBER_OF_PRODUCTS);
        int scanfResult = scanf("%d", &productNumber);

        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (productNumber < 0 || productNumber > NUMBER_OF_PRODUCTS) {
            puts("You've entered incorrect product number. Try again.");
        }
    } while (productNumber < 0 || productNumber > NUMBER_OF_PRODUCTS);

    return productNumber;
}

static int getQuantitySold(void) {
    int quantitySold = -1;

    do {
        printf("%s", "Enter quantity sold: ");
        int scanfResult = scanf("%d", &quantitySold);

        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (quantitySold < 0) {
            puts("You've entered incorrect quantity. Try again.");
        }
    } while (quantitySold < 0);

    return quantitySold;
}

static void increaseProductQuantity(int productQuantities[NUMBER_OF_PRODUCTS + 1],
                                    const int productNumber,
                                    const int quantity) {
    if (productNumber <= 0) {
        printf(
            "Incorrect product number: %d\n"
            "Shutting down...",
            productNumber);
        exit(EXIT_FAILURE);
    }

    if (quantity < 0) {
        printf(
            "Incorrect quantity: %d\n"
            "Shutting down...",
            quantity);
        exit(EXIT_FAILURE);
    }

    productQuantities[productNumber] += quantity;
}

static void calculateAndPrintTotalRevenue(const int productQuantities[NUMBER_OF_PRODUCTS + 1]) {
    printf(
        "%-15s%-13s%-14s\n",
        "Product Number",
        "Retail price",
        "Total revenue");
    for (int product = 1; product <= NUMBER_OF_PRODUCTS; ++product) {
        printf(
            "%-15d$%-12.2f$%-13.2f\n",
            product,
            prices[product],
            prices[product] * productQuantities[product]);
    }
}

int main(void) {
    int productQuantities[NUMBER_OF_PRODUCTS + 1] = {0};

    int productNumber = getProductNumber();
    while (productNumber != 0) {
        const int quantitySold = getQuantitySold();

        increaseProductQuantity(productQuantities, productNumber, quantitySold);

        productNumber = getProductNumber();
    }

    calculateAndPrintTotalRevenue(productQuantities);

    return EXIT_SUCCESS;
}
