#include "start.h"
#include "input.h"
#include "output.h"

void start(void) {
    int size;
    char **words = input(&size);
    output(words, size);
}