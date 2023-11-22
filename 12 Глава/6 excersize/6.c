#include "create_array.h"

int main(void) {
    int arr[ARRLEN] = {0};
    create_array(arr);
    output_array(arr);
    return 0;
}