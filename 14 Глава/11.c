#include <stdio.h>
#include <math.h>

double to_rads(double degrees) {
    return degrees * (M_PI / 180);
}

void transform(double *source, double *target, int size, double(*foo)(double)) {
    for (int i = 0; i < size; ++i) {
        target[i] = foo(source[i]);
    }
}

int main(void) {
    double rads[5] = {to_rads(120), to_rads(30), to_rads(0), to_rads(90), to_rads(-90)};
    double rads_changed[5];
    transform(rads, rads_changed, 5, sin);
    for (int i = 0; i < 5; ++i) {
        printf("%lf ", rads_changed[i]);
    }
}