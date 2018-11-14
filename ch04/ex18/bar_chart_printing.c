#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_BAR_CHART_LINES 5
#define BAR_CHART_SYMBOL_AS_STRING "*"

static int getBarChartLineLength(void) {
    int lineLength = -1;

    do {
        printf("%s", "Enter bar chart line length (1-30): ");
        int scanfResult = scanf("%d", &lineLength);

        if (scanfResult != 1) {
            fflush(stdin);
        }

        if (lineLength <= 0 || lineLength > 30) {
            puts("You've entered incorrect length. Try again.");
        }
    } while (lineLength <= 0 || lineLength > 30);

    return lineLength;
}

static void printBarChartLine(const int barChartLineLength) {
    int remainingLength = barChartLineLength;
    while (remainingLength > 0) {
        printf("%s", BAR_CHART_SYMBOL_AS_STRING);
        --remainingLength;
    }
}

static void printBarChart(const int barChartLinesLengths[NUMBER_OF_BAR_CHART_LINES]) {
    for (int barChartLine = 0; barChartLine < NUMBER_OF_BAR_CHART_LINES; ++barChartLine) {
        printBarChartLine(barChartLinesLengths[barChartLine]);
        puts("");
    }
}

int main(void) {
    int barChartLinesLengths[NUMBER_OF_BAR_CHART_LINES] = {};
    for (int barChartLine = 0; barChartLine < NUMBER_OF_BAR_CHART_LINES; ++barChartLine) {
        barChartLinesLengths[barChartLine] = getBarChartLineLength();
    }

    puts("");
    printBarChart(barChartLinesLengths);

    return EXIT_SUCCESS;
}
