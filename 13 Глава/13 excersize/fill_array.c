#include "fill_array.h"
#include <stdio.h>
#include <stdlib.h>
void fill_array(void) {
    const char file_name[] = "data.txt";
    FILE *fp = fopen(file_name, "r");
    // Memory allocation
    // char **field = (char**)malloc(sizeof(char*)*Y);
    // for (int y = 0; y < Y; ++y) {
    //     field[y] = (char*)malloc(sizeof(char)*X);
    // }
    
    // Array creation
    char ch[X_SPACED];
    for (int y = 0; y < Y; ++y) {
        fgets(ch, X_SPACED, fp);
        for (int x = 0, x_not_spaced = 0; x < X_SPACED; ++x) {
            if (ch[x] >= '0' && ch[x] <= '9') {
                field[y][x_not_spaced++] = decide_light(ch[x]);
            }
        }
    }
}

char decide_light(char ch) {
    const int syms_lighting[LEVELS_LIGHTING] = {' ', '.', '\'', ':', '~', '*', '=', '(', '%', '#'};
    return syms_lighting[(int)ch - 48];
}