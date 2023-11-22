#include "output.h"
#include <stdio.h>
void output(char **arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s\n", arr[i]);
    }
}