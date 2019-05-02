#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#define SIZE_OF_PRINT_FIGURE_HANDLERS_TABLE 4

#define LAST_FIGURE_TO_PRINT PRINT_FIGURE_DIAMOND

#define MIN_RECTAGLE_SIDE_LENGTH 2

#define MIN_HOLLOW_SQUARE_SIDE_LENGTH 3

enum PrintFigureType {
    PRINT_FIGURE_EXIT = 0,
    PRINT_FIGURE_RECTANGLE = 1,
    PRINT_FIGURE_HOLLOW_SQUARE = 2,
    PRINT_FIGURE_DIAMOND = 3,
};

typedef void (*print_figure_handler_t)(void);

static void handlePrintFigureExit(void);
static void handlePrintFigureRectangle(void);
static void handlePrintFigureHollowSquare(void);
static void handlePrintFigureDiamond(void);

static print_figure_handler_t printFigureHandlers[SIZE_OF_PRINT_FIGURE_HANDLERS_TABLE] = {
    handlePrintFigureExit,
    handlePrintFigureRectangle,
    handlePrintFigureHollowSquare,
    handlePrintFigureDiamond
};

// Common.
static void promptEnterFigureToPrint(void) {
    printf(
        "%s\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s: %d.\n"
        "%s",
        "Enter number of figure you want to print.",
        "Rectangle", PRINT_FIGURE_RECTANGLE,
        "Hollow square", PRINT_FIGURE_HOLLOW_SQUARE,
        "Diamond", PRINT_FIGURE_DIAMOND,
        "To exit enter", PRINT_FIGURE_EXIT,
        "Figure to print: ");
}

static int getFigureToPrint(void) {
    int figureToPrint = PRINT_FIGURE_EXIT - 1;

    do {
        promptEnterFigureToPrint();

        const int scanfResult = scanf("%d", &figureToPrint);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (figureToPrint < PRINT_FIGURE_EXIT || figureToPrint > LAST_FIGURE_TO_PRINT) {
            puts("\nYou've entered incorrect figure number. Try again.");
        }
    } while (figureToPrint < PRINT_FIGURE_EXIT || figureToPrint > LAST_FIGURE_TO_PRINT);

    return figureToPrint;
}

static int getFillCharacter(void) {
    char fillCharacter = '#';
    int scanfResult = 0;

    fflush(stdin);
    do {
        printf("%s", "Enter fill character you want to draw your figure with: ");

        scanfResult = scanf("%c", &fillCharacter);
        if (scanfResult != 1) {
            fflush(stdin);
            puts("You've entered incorrect fill character. Try again.");
        }
    } while (scanfResult != 1);

    return fillCharacter;
}

static void handlePrintFigureExit(void) {
    puts("Exit.");
}

// Rectangle.
static int getRectangleSide(const char *side) {
    int rectangleSide = 0;

    do {
        printf("Enter %s rectangle side length: ", side);

        const int scanfResult = scanf("%d", &rectangleSide);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (rectangleSide < MIN_RECTAGLE_SIDE_LENGTH) {
            puts("You've entered incorrect rectangle side length. Try again.");
        }
    } while (rectangleSide < MIN_RECTAGLE_SIDE_LENGTH);

    return rectangleSide;
}

static void printRectangle(const int side1,
                           const int side2,
                           const char fillCharacter) {
    for (int s1 = 0; s1 < side1; ++s1) {
        for (int s2 = 0; s2 < side2; ++s2) {
            printf("%c ", fillCharacter);
        }
        puts("");
    }
}

static void handlePrintFigureRectangle(void) {
    const int side1 = getRectangleSide("first");
    const int side2 = getRectangleSide("second");
    const char fillCharacter = getFillCharacter();

    puts("");
    printRectangle(side1, side2, fillCharacter);
}

// Hollow square.
static int getHollowSquareSide(void) {
    int squareSide = 0;

    do {
        printf("Enter hollow rectangle side length (minimum 3): ");

        const int scanfResult = scanf("%d", &squareSide);
        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (squareSide < MIN_HOLLOW_SQUARE_SIDE_LENGTH) {
            puts("You've entered incorrect hollow square side length. Try again.");
        }
    } while (squareSide < MIN_HOLLOW_SQUARE_SIDE_LENGTH);

    return squareSide;
}

static void printHollowSquareFullRow(const int numberOfColumns, const char fillCharacter) {
    int columns = numberOfColumns;
    while (columns > 0) {
        printf("%c", fillCharacter);
        --columns;
    }
    printf("%s", "\n");
}

static void printHollowSquareHollowRow(const int numberOfColumns, const char fillCharacter) {
    // Print first symbol.
    printf("%c", fillCharacter);

    // Print hollowed columns.
    // Number of columns minus first and last columns.
    int columns = numberOfColumns - 2;
    while (columns > 0) {
        printf("%c", ' ');
        --columns;
    }

    // Print last symbol.
    printf("%c\n", fillCharacter);
}

static void drawHollowSquare(const int squareSide, const char fillCharacter) {
    // We need to print full first row and full last row.
    // All other rows will have hollow inside.

    // We can't print hollow square with side less than 3.
    if (squareSide < 3) {
        int rows = squareSide;
        while (rows > 0) {
            printHollowSquareFullRow(squareSide, fillCharacter);
            --rows;
        }
        return;
    }

    // Print first row.
    printHollowSquareFullRow(squareSide, fillCharacter);

    // Print hollowed rows.
    // Square side - first and last rows.
    int rows = squareSide - 2;
    while (rows > 0) {
        printHollowSquareHollowRow(squareSide, fillCharacter);
        --rows;
    }
    // Print last row.
    printHollowSquareFullRow(squareSide, fillCharacter);
}

static void handlePrintFigureHollowSquare(void) {
    const int squareSide = getHollowSquareSide();
    const char fillCharacter = getFillCharacter();

    puts("");
    drawHollowSquare(squareSide, fillCharacter);
}

// Diamond.
static void printDiamondRow(const int width, const int numberOfSymbols, const char fillCharacter) {
    // Width and number of symbols should be an odd numbers.
    // Otherwise we can't print right diamond.
    // Of course width and number of symbols can't be negative.
    if ((width % 2 <= 0) || (numberOfSymbols % 2 <= 0)) {
        puts("Diamond row width and number of symbols should be positive odd numbers.");
        exit(EXIT_FAILURE);
    }

    // First we need to find number of blanks before and after rows.
    const int numberOfBlanks = width - numberOfSymbols;
    if (numberOfBlanks < 0) {
        puts("Number of symbols in row can't be greater than row width.");
        exit(EXIT_FAILURE);
    }

    // Print blanks before.
    for (int blanksBefore = numberOfBlanks / 2; blanksBefore > 0; --blanksBefore) {
        putchar(' ');
    }

    // Print symbols.
    for (int symbols = numberOfSymbols; symbols > 0; --symbols) {
        putchar(fillCharacter);
    }

    // Print blanks after.
    for (int blanksAfter = numberOfBlanks / 2; blanksAfter > 0; --blanksAfter) {
        putchar(' ');
    }

    puts("");
}

static void printDiamond(const int numberOfRows, const char fillCharacter) {
    // Number of rows should be positive odd number.
    if (numberOfRows % 2 <= 0) {
        puts("Number of rows in diamond should be positive odd number.");
        exit(EXIT_FAILURE);
    }

    // Print top half of diamond.
    int numberOfSymbols = 1;

    for (int row = 0; row < numberOfRows / 2; ++row) {
        printDiamondRow(numberOfRows, numberOfSymbols, fillCharacter);
        numberOfSymbols += 2;
    }

    // Print bottom half of diamond.
    for (int row = numberOfRows; row > numberOfRows / 2; --row) {
        printDiamondRow(numberOfRows, numberOfSymbols, fillCharacter);
        numberOfSymbols -= 2;
    }
}

static int getDiamondSize(void) {
    int diamondSize = -1;

    bool isUserInputValid = false;
    while (!isUserInputValid) {
        printf("%s", "Enter diamond size (positive odd number): ");
        const int scanfResult = scanf("%d", &diamondSize);

        isUserInputValid = scanfResult == 1 && !(diamondSize % 2 == 0);

        if (!isUserInputValid) {
            fflush(stdin);
            puts("You've entered incorrect diamond size. Try again.");
        }
    };

    return diamondSize;
}

static void handlePrintFigureDiamond(void) {
    const int diamondSize = getDiamondSize();
    const char fillCharacter = getFillCharacter();

    puts("");
    printDiamond(diamondSize, fillCharacter);
}

int main(void) {
    while (true) {
        const enum PrintFigureType figureToPrint = getFigureToPrint();
        if (figureToPrint == PRINT_FIGURE_EXIT) {
            break;
        }
        puts("");
        printFigureHandlers[figureToPrint]();
        puts("");
    }
    return EXIT_SUCCESS;
}
