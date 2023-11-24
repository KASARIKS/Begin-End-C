#include "clear_interference.h"
#include <math.h>
#include <stdlib.h>
#include "lighting.h"
#include "field_sizes.h"

int is_interference(char val, char top, char right, char left, char bottom) {
    if (abs(change_lighting_to_int(val) - change_lighting_to_int(top)) > 1) return 1;
    if (abs(change_lighting_to_int(val) - change_lighting_to_int(right)) > 1) return 1;
    if (abs(change_lighting_to_int(val) - change_lighting_to_int(left)) > 1) return 1;
    if (abs(change_lighting_to_int(val) - change_lighting_to_int(bottom)) > 1) return 1;

    return 0;
}

void clear_interference(char **field) {
    // Top clearing
    for (int x = 1; x < X - 1; ++x) {
        if (is_interference(field[0][x], field[1][x], field[0][x + 1], field[0][x - 1], field[1][x])) {
            int average_l = average_lighting(field[1][x], field[0][x + 1], field[0][x - 1], field[1][x]);
            field[0][x] = decide_light(average_l + 48);
        }
    }
    // Bottom clearing
    for (int x = 1; x < X - 1; ++x) {
        if (is_interference(field[Y - 1][x], field[Y - 2][x], field[Y - 1][x + 1], field[Y - 1][x - 1], field[Y - 2][x])) {
            int average_l = average_lighting(field[Y - 2][x], field[Y - 1][x + 1], field[Y - 1][x - 1], field[Y - 2][x]);
            field[Y - 1][x] = decide_light(average_l + 48);
        }
    }
    // Left clearing
    for (int y = 1; y < Y - 1; ++y) {
        if (is_interference(field[y][0], field[y - 1][0], field[y][1], field[y][1], field[y + 1][0])) {
            int average_l = average_lighting(field[y - 1][0], field[y][1], field[y][1], field[y + 1][0]);
            field[y][0] = decide_light(average_l + 48);
        }
    }
    // Right clearing
    for (int y = 1; y < Y - 1; ++y) {
        if (is_interference(field[y][X - 1], field[y - 1][X - 1], field[y][X - 2], field[y][X - 2], field[y + 1][X - 1])) {
            int average_l = average_lighting(field[y - 1][X - 1], field[y][X - 2], field[y][X - 2], field[y + 1][X - 1]);
            field[y][0] = decide_light(average_l + 48);
        }
    }
    // Middle clearing
    for (int y = 1; y < Y - 1; ++y) {
        for (int x = 1; x < X - 1; ++x) {
            if (is_interference(field[y][x], field[y - 1][x], field[y][x + 1], field[y][x - 1], field[y + 1][x])) {
                int average_l = average_lighting(field[y - 1][x], field[y][x + 1], field[y][x - 1], field[y + 1][x]);
                field[y][x] = decide_light(average_l + 48);
            }
        }
    }
}