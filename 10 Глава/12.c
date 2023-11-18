#include <stdio.h>
#define MONTHS 12
#define YEARS 5

void start(void);
void counting(const float[YEARS][MONTHS], int*, int*, float*, float*);
void count_year(const float[YEARS][MONTHS], int*, int*, float*, float*);
void count_average(const float[YEARS][MONTHS], int*, int*, float*, float*);

int main(void) {
    start();
    return 0;
}

void start(void) {
    // Data
    const float rain[YEARS][MONTHS] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    int year, month;
    float subtot, total;
    counting(rain, &year, &month, &subtot, &total);
}

void counting(const float rain[YEARS][MONTHS], int *year, int *month, float *subtot, float *total) {
    printf("YEAR NUMBER OF RAINS (in duemes)\n");
    count_year(rain, year, month, subtot, total);

    printf("\nAverage of year number of rains is %.1f duemes.\n\n", *total/YEARS);
    printf("AVERAGE OF MONTH NUMBER OF RAINS:\n\n");
    printf(" Yan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    count_average(rain, year, month, subtot, total);

    printf("\n");
}

void count_year(const float rain[YEARS][MONTHS], int *year, int *month, float *subtot, float *total) {
    for (*year = 0, *total = 0; *year < YEARS; ++*year)
    {
        for (*month = 0, *subtot = 0; *month < MONTHS; *month++)
            *subtot += rain[*year][*month];
        printf("%5d %15.1f\n", 2010 + *year, *subtot);
        *total += *subtot;
    }
}

void count_average(const float rain[YEARS][MONTHS], int *year, int *month, float *subtot, float *total) {
    for (*month = 0; *month < MONTHS; ++*month)
    {
        for (*year = 0, *subtot = 0; *year < YEARS; ++*year)
            *subtot += rain[*year][*month];
        printf("%4.1f", *subtot/YEARS);
    }
}