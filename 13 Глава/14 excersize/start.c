#include "start.h"
#include "fill_array.h"
#include "output.h"
#include <stdio.h>
void start(void) {
    char **field = fill_array();
    output(field, Y, X);
}