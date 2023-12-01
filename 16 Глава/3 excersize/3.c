#include "polars_cords.h"
#include "quads_cords.h"
#include <stdio.h>
#include <math.h>

struct quads_cords cast(struct polars_cords *pol_cords) {
    struct quads_cords q_cords = {
        pol_cords->r * cos(pol_cords->A),
        pol_cords->r * sin(pol_cords->A)
    };
    return q_cords;
}

int main(void) {
    struct polars_cords pol_cords;
    printf("Input r and A: ");
    while (scanf("%f %f", &pol_cords.r, &pol_cords.A) != 2) {
        printf("WRONG INPUT!\n");
        printf("Input r and A: ");
        fflush(stdin);
    }
    struct quads_cords q_cords = cast(&pol_cords);
    printf("New cords: %f %f\n", q_cords.x, q_cords.y);
    return 0;
}