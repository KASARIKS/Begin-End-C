#include "bones_throw.h"
#include <stdlib.h>

int bones_throw(int sides, int bones) {
    int res = 0;
    for (int bone = 0; bone < bones; ++bone) {
        res += 1 + rand() % sides;
    }
    return res;
}