#include <stdio.h>

double power(double, int);

int main(void) {
    printf("%lf", power(-32, 2));
    return 0;
}

double power(double n, int p) {
    if (n == 0) return 0;

    double pow = 1;
    int i;
    if (p > 0)
        for (i = 1; i <= p; ++i) 
            pow *= n;
    else if (p < 0)
        for (i = 1; i < -p; ++i) 
            pow /= n;
        
    return pow;
}