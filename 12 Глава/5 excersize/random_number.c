#include "random_number.h"
#include <stdlib.h>

int random_number(void) {
    return 1 + rand() % 10;
}