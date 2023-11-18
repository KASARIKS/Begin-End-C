#include <stdio.h>

double power(double, int, int, double);

int main(void) {
    printf("%lf", power(0, -2, 1, 1));
    return 0;
}

double power(double n, int p, int i, double pow) {
    if (p > 0 && i <= p) {
        return power(n, p, ++i, pow *= n);
    }
    else if (p < 0 && i < -p) {
        return power(n, p, ++i, pow /= n);
    }

    return pow;
}