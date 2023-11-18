#include <stdio.h>
#define SMALLEST(a, b) a < b ? a : b
#define BIGGEST(a, b) a > b ? a : b
#define AVERAGE(a, b, c) (a + b + c) / 3

double foo(double*, double*, double*);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    double a, b, c;
    a = 1, b = 10, c = 500;
    printf("%.0lf, %.0lf, %.0lf = ", a, b, c);
    foo(&a, &b, &c);
    printf("%.0lf, %.2lf, %.0lf\n", a, b, c);
    a = 5000, b = -100, c = -1000;
    printf("%.0lf, %.0lf, %.0lf = ", a, b, c);
    foo(&a, &b, &c);
    printf("%.0lf, %.2lf, %.0lf\n", a, b, c);
    a = 1, b = 1, c = 1;
    printf("%.0lf, %.0lf, %.0lf = ", a, b, c);
    foo(&a, &b, &c);
    printf("%.0lf, %.2lf, %.0lf\n", a, b, c);
    a = 1, b = 100, c = 1;
    printf("%.0lf, %.0lf, %.0lf = ", a, b, c);
    foo(&a, &b, &c);
    printf("%.0lf, %.2lf, %.0lf\n", a, b, c);
    a = 100, b = 10, c = 100;
    printf("%.0lf, %.0lf, %.0lf = ", a, b, c);
    foo(&a, &b, &c);
    printf("%.0lf, %.2lf, %.0lf\n", a, b, c);
}

double foo(double *a, double *b, double *c) {
    double a_c = *a, b_c = *b;
    // Smallest
    *a = SMALLEST(b_c, *c);
    *a = SMALLEST(a_c, *a);
    
    // Average
    *b = AVERAGE(a_c, b_c, *c);

    // Biggest
    *c = BIGGEST(b_c, *c);
    *c = BIGGEST(*c, a_c);
}