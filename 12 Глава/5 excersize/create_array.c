#include "create_array.h"
#include "random_number.h"
#include <stdlib.h>
#include <stdio.h>

int comp (const int *i, const int *j)
{
    return *i - *j;
}

int *create_array(int *arr) {
    for (int i = 0; i < ARRLEN; ++i) {
        arr[i] = random_number();
    }
    qsort(arr, ARRLEN, sizeof(int), (int(*) (const void *, const void *))comp);
    return arr;
}
void output_array(int *arr) {
    for (int i = 0; i < ARRLEN; ++i) printf("arr[%d] = %d\n", i, arr[i]);
}