#include <stdio.h>

void Temperatures(double F) {
    const double f = F, c = 5.0 / 9.0 * (F - 32.0), k = c + 273.16;
    printf("Temperature in Farengate: %.2lf\n", f);
    printf("Temperature in Celsiy: %.2lf\n", c);
    printf("Temperature in Kelvin: %.2lf\n", k);
}

int main(void) {
    double F;
    printf("Input temperature in Farengate: ");
    while (scanf("%lf", &F) == 1) {
        Temperatures(F);
        printf("Input temperature in Farengate: ");
    }
    return 0;
}