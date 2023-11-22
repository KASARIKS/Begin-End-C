#include "4_foo.h"
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 10; ++i) {
        printf("The function had been called %d times.\n", foo());
    }
}