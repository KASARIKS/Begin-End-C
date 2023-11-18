#include <stdio.h>
#define MIN(x, y) x > y ? y : x

void driver(void) {
    printf("10.0 10.0 = %lf\n", MIN(10.0, 10.0));
    printf("10.1 10.0 = %lf\n", MIN(10.1, 10.0));
    printf("10.0 10.1 = %lf\n", MIN(10.0, 10.1));
} 

int main(void) {
    driver();
    return 0;
}