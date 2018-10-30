#include <stdio.h>
#include <stdlib.h>

#define world_population_size_t unsigned long long
#define WORLD_POPULATION_SIZE_T_FORMAT_SPECIFIER "%llu"

world_population_size_t getCurrentWorldPopulation(void) {
    world_population_size_t currentWorldPopulation = 0;

    printf("%s", "Enter current world population: ");
    scanf(WORLD_POPULATION_SIZE_T_FORMAT_SPECIFIER, &currentWorldPopulation);

    return currentWorldPopulation;
}

float getWorldPopulationGrowthRate(void) {
    float worldPopulationGrowthRate = 0;

    printf("%s", "Enter world population growth rate: ");
    scanf("%f", &worldPopulationGrowthRate);

    return worldPopulationGrowthRate;
}

world_population_size_t predictWorldPopulation(
    const int afterYears,
    const world_population_size_t currentPopulation,
    const float currentGrowthRate) {
    world_population_size_t populationAfter = currentPopulation;

    int counter = afterYears;
    while (counter > 0) {
        populationAfter += populationAfter * currentGrowthRate;
        --counter;
    }

    return populationAfter;
}

void printEstimatedWorldPopulation(
    const int afterYears,
    const world_population_size_t initialPopulation,
    const world_population_size_t estimatedPopulation) {
    printf(
        "After %d years, current population of "
        WORLD_POPULATION_SIZE_T_FORMAT_SPECIFIER
        " people will increase to "
        WORLD_POPULATION_SIZE_T_FORMAT_SPECIFIER
        "\n",
        afterYears,
        initialPopulation,
        estimatedPopulation);
}

int main(void) {
    const world_population_size_t currentWorldPopulation = getCurrentWorldPopulation();
    const float worldPopulationGrowthRate = getWorldPopulationGrowthRate();

    int years = 1;
    while (years <= 5) {
        const world_population_size_t estimatedPopulation =
            predictWorldPopulation(years, currentWorldPopulation, worldPopulationGrowthRate);
        printEstimatedWorldPopulation(years, currentWorldPopulation, estimatedPopulation);

        ++years;
    }

    return EXIT_SUCCESS;
}
