#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void compareExpressionsAndPrintResult(
    const char* originalExpression,
    const bool originalExpressitonResult,
    const char* rewrittenExpression,
    const bool rewrittenExpressionResult) {
    if (originalExpressitonResult == rewrittenExpressionResult) {
        printf(
            "%s original expression is equal to %s rewritten expression.\n",
            originalExpression,
            rewrittenExpression);
    } else {
        printf(
            "%s original expression is not equal to %s rewritten expression.\n",
            originalExpression,
            rewrittenExpression);
    }
}

int main(void) {
    const int x = 6;
    const int y = 6;
    const int a = 2;
    const int b = 2;
    const int g = 5;
    const int i = 8;
    const int j = 9;

    compareExpressionsAndPrintResult(
        "!(x < 5) && !(x >= 7)",
        !(x < 5) && !(x >= 7),
        "!((x < 5) || (x >= 7))",
        !((x < 5) || (x >= 7))
    );
    compareExpressionsAndPrintResult(
        "!(a == b) || !(g != 5)",
        !(a == b) || !(g != 5),
        "!(a == b && g != 5)",
        !(a == b && g != 5)
    );
    compareExpressionsAndPrintResult(
        "!((x <= 8) && (y > 4))",
        !((x <= 8) && (y > 4)),
        "!(x <= 8) || !(y > 4)",
        !(x <= 8) || !(y > 4)
    );
    compareExpressionsAndPrintResult(
        "!((i > 4) || (j <= 6))",
        !((i > 4) || (j <= 6)),
        "(!(i > 4) && !(j <= 6))",
        (!(i > 4) && !(j <= 6))
    );

    return EXIT_SUCCESS;
}
