// Experiments
#include <stdio.h>

int main(void) {
    int a = 15e300;
    printf("a: %d\n", a);
    float b = 7.0;
    printf("b: %f\n", b);
    printf("b / 4: %f\n", b / 4);
    printf("b / 100000000: %f\n", b / 100000000);
    printf("b * 10e350: %f\n", b * 10e350);
    printf("b * 0.1e-4: %f\n", b * 0.1e-4);
    printf("b * 0.1e-5: %f\n", b * 0.1e-5);
    printf("b * 0.1e-6: %f\n", b * 0.1e-6);
    printf("b * 0.1e-7: %f\n", b * 0.1e-7);
    printf("b * 0.1e-8: %f\n", b * 0.1e-8);
 
    return 0;
}