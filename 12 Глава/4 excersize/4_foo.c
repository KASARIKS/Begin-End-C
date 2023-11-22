#include "4_foo.h"

int call_counter = 0;
int foo(void) {
    return ++call_counter;
}