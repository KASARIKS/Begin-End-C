#include "create_array.h"
#include <stdlib.h>

int main(void) {
    int *arr = (int*)malloc(sizeof(int)*ARRLEN);
    create_array(arr);
    output_array(arr);
    free(arr);
    return 0;
}