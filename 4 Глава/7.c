#include <stdio.h>
#include <float.h>

int main(void) {
    double res_d = 1.0 / 3.0;
    float res_f = 1.0 / 3.0;

    printf("d: %.4lf\n", res_d);
    printf("f: %.4f\n", res_f);
    printf("d: %.12lf\n", res_d);
    printf("d: %.12f\n", res_f);
    printf("d: %.16lf\n", res_d);
    printf("d: %.16f\n", res_f);
    printf("D: %lf\n", DBL_DIG);
    printf("F: %f\n\n", FLT_DIG);

    res_d = 1.0 / 0.3;
    res_f = 1.0 / 0.3;

    printf("d: %.4lf\n", res_d);
    printf("f: %.4f\n", res_f);
    printf("d: %.12lf\n", res_d);
    printf("d: %.12f\n", res_f);
    printf("d: %.16lf\n", res_d);
    printf("d: %.16f\n", res_f);
    printf("D: %lf\n", DBL_DIG);
    printf("F: %f\n\n", FLT_DIG);

    return 0;
}