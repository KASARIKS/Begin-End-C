#include "lighting.h"
#include <math.h>
#define LEVELS_LIGHTING 10
const int syms_lighting[LEVELS_LIGHTING] = {' ', '.', '\'', ':', '~', '*', '=', '(', '%', '#'};

char decide_light(char ch) {
    return syms_lighting[(int)ch - 48];
}

int change_lighting_to_int(char val) {
    for (int i = 0; i < LEVELS_LIGHTING; ++i) {
        if (val == syms_lighting[i]) return i;
    }
    return -1;
}

int average_lighting(char top, char right, char left, char bottom) {
    return (int)round((change_lighting_to_int(top) 
                + change_lighting_to_int(right)  
                + change_lighting_to_int(left)  
                + change_lighting_to_int(bottom) ) / 4);    
}