// According to http://www.worldometers.info/world-population/ information.

#include <stdio.h>
#include <stdlib.h>

#define CURRENT_YEAR 2019
#define CURRENT_WORLD_POPULATION 7686360230
#define CURRENT_WORLD_POPULATION_GROWTH_RATE 0.0107
#define CURRENT_WORLD_POPULATION_GROWTH_RATE_CHANGE (-0.00025)

int main(void) {
    printf("%s%d\n"
           "%s%llu\n"
           "%s%.4f\n"
           "%s%.5f\n",
           "Current year is ", CURRENT_YEAR,
           "Current world population is ", CURRENT_WORLD_POPULATION,
           "Current world population growth rate is ", CURRENT_WORLD_POPULATION_GROWTH_RATE,
           "Current world population growth rate change is ", CURRENT_WORLD_POPULATION_GROWTH_RATE_CHANGE);

    long long current_year_population = CURRENT_WORLD_POPULATION;
    double current_year_population_growth_rate = CURRENT_WORLD_POPULATION_GROWTH_RATE;

    printf("\n%-4s %s\n",
           "Year", "Population");
    for (int year = CURRENT_YEAR + 1; year <= CURRENT_YEAR + 75; ++year) {
        current_year_population += current_year_population * current_year_population_growth_rate;
        printf("%-4d %llu\n",
               year, current_year_population);
        current_year_population_growth_rate += CURRENT_WORLD_POPULATION_GROWTH_RATE_CHANGE;
    }

    return EXIT_SUCCESS;
}
