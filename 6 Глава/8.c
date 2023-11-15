#include <stdio.h>
#define COUNT(a, b) (a - b) / (a * b)

int main(void) {
    float a, b;
    printf("Input 2 real numbers separated by a space(or not number for exit): ");
    while (scanf("%f %f", &a, &b) == 2) {
        printf("%f\n", COUNT(a, b));
        fflush(stdin);
        printf("Input 2 real numbers separated by a space(or not number for exit): ");
    }

    return 0;
}