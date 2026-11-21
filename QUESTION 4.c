#include <stdio.h>

#define DISTRICTS 38
#define MONTHS 12

void readRainfall(float rain[DISTRICTS][MONTHS]) {
    for (int i = 0; i < DISTRICTS; i++) {
        printf("\nEnter rainfall for District %d:\n", i + 1);
        for (int j = 0; j < MONTHS; j++) {
            printf("Month %d: ", j + 1);
            scanf("%f", &rain[i][j]);
        }
    }
}

void calculateDistrictTotals(const float rain[DISTRICTS][MONTHS],
                             float totals[DISTRICTS]) {
    for (int i = 0; i < DISTRICTS; i++) {
        totals[i] = 0.0f;
        for (int j = 0; j < MONTHS; j++)
            totals[i] += rain[i][j];
    }
}

void calculateMonthlyAverages(const float rain[DISTRICTS][MONTHS],
                              float averages[MONTHS]) {
    for (int j = 0; j < MONTHS; j++) {
        float sum = 0.0f;
        for (int i = 0; i < DISTRICTS; i++)
            sum += rain[i][j];
        averages[j] = sum / DISTRICTS;
    }
}

void findWettestMonth(const float rain[DISTRICTS][MONTHS],
                      int *district, int *month, float *maximum) {
    *maximum = rain[0][0];
    *district = 0;
    *month = 0;

    for (int i = 0; i < DISTRICTS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            if (rain[i][j] > *maximum) {
                *maximum = rain[i][j];
                *district = i;
                *month = j;
            }
        }
    }
}

void findDeficientDistricts(const float totals[DISTRICTS]) {
    float stateTotal = 0.0f;
    for (int i = 0; i < DISTRICTS; i++)
        stateTotal += totals[i];

    float average = stateTotal / DISTRICTS;
    float limit = 0.60f * average;

    printf("\nDeficient districts (below 60%% of average annual total):\n");
    int found = 0;
    for (int i = 0; i < DISTRICTS; i++) {
        if (totals[i] < limit) {
            printf("District %d: %.2f mm\n", i + 1, totals[i]);
            found = 1;
        }
    }
    if (!found) printf("No deficient districts.\n");
}

int main(void) {
    float rain[DISTRICTS][MONTHS];
    float totals[DISTRICTS], averages[MONTHS];
    int district, month;
    float maximum;

    readRainfall(rain);
    calculateDistrictTotals(rain, totals);
    calculateMonthlyAverages(rain, averages);
    findWettestMonth(rain, &district, &month, &maximum);

    printf("\nANNUAL RAINFALL TOTALS\n");
    for (int i = 0; i < DISTRICTS; i++)
        printf("District %d: %.2f mm\n", i + 1, totals[i]);

    printf("\nMONTHLY STATE AVERAGES\n");
    for (int j = 0; j < MONTHS; j++)
        printf("Month %d: %.2f mm\n", j + 1, averages[j]);

    printf("\nWettest district-month: District %d, Month %d (%.2f mm)\n",
           district + 1, month + 1, maximum);

    findDeficientDistricts(totals);
    return 0;
}
