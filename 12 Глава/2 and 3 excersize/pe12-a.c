#include "pe12-a.h"
#include <stdio.h>

void set_mode(int *mode) {
    while (*mode != 0 && *mode != 1) {
        printf("Not alloweded mode!\n");
        printf("Input 0 for metrci mode or 1 for american mode: ");
        scanf("%d", mode);
    }
}
void get_info(double *trip, double *fuel) {
    printf("Input trip: ");
    while (scanf("%lf", trip) != 1) {
        printf("Input only real numbers!\n");
        printf("Input trip: ");
        fflush(stdin);
    }

    printf("Input burned fuel: ");
    while (scanf("%lf", fuel) != 1) {
        printf("Input only real numbers!\n");
        printf("Input trip: ");
        fflush(stdin);
    }
}
void show_info(int mode, double trip, double fuel) {
    if (mode == 0) {
        printf("Fuel range is %lf lt/km.\n", fuel / trip * 100);
    } else if (mode == 1) {
        printf("Fuel range is %lf ml/gl.\n", trip / fuel);
    }
}