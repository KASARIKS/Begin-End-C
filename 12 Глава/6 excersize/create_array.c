#include "create_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUMS 1000

void create_array(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < NUMS; ++i) {
        int num = 1 + rand() % 10;
        ++arr[num - 1];
    }
}

void output_array(int *arr) {
    for (int i = 0; i < ARRLEN; ++i) printf("arr[%d] = %d\n", i, arr[i]);
}