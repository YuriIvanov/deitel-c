#include <stdio.h>
#include <stdlib.h>

static double celsiusToFahrenheit(const double celcius) {
    return (9 * celcius / 5) + 32;
}

int main(void) {
    printf("%-12s%-12s\n", "Celsius", "Fahrenheit");
    for (int temperatureInCelcius = 30;
            temperatureInCelcius <= 50;
            ++temperatureInCelcius) {
        printf(
            "%-12d%-12.2f\n",
            temperatureInCelcius,
            celsiusToFahrenheit(temperatureInCelcius));
    }

    return 0;
}
