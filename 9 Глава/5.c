#include <stdio.h>

double larger_of(double*, double*);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    double a = 0, b = 10;
    larger_of(&a, &b);
    printf("0, 10 = %lf %lf\n", a, b);
    a = 1.5, b = -1.5;
    larger_of(&a, &b);
    printf("1.5 -1.5 = %lf %lf\n", a, b);
}

double larger_of(double *a, double *b) {
    if (*a > *b) *b = *a;
    else *a = *b;
}