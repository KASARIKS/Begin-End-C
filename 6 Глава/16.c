#include <stdio.h>
#define SIMPLE 10
#define HARD 5
#define START_SUM 100

int main(void) {
    float dd = START_SUM, df = START_SUM;
    int year;
    for (year = 0; dd >= df; ++year) {
        dd += START_SUM * 0.1;
        df *= 1.05;
    }
    printf("%d", year);
    return 0;
}