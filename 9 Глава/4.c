#include <stdio.h>

double average_harmonic(double, double);
void driver(void);

int main(void) {
    driver();
    return 0;
}

double average_harmonic(double a, double b) {
    return 2 / ((1 / a) + (1 / b));
}

void driver(void) {
    printf("%lf\n", average_harmonic(1, 1));
    printf("%lf\n", average_harmonic(10, 10));
    printf("%lf\n", average_harmonic(1, 10));
    printf("%lf\n", average_harmonic(-5, 10));
}