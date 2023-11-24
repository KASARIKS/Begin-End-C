#include "output.h"
#include <stdio.h>

void output(char field[Y][X], int y, int x) {
    for (int y_i = 0; y_i < Y; ++y_i) {
        for (int x_i = 0; x_i < X - 1; ++x_i) {
            printf("%c", field[y_i][x_i]);
        }
        printf("\n");
    }
}