#include <stdio.h>
#define SUM(a, b) a + b

void foo(double*, double*, double*, int);
void output(double *t, int n);

int main(void) {
    double n1[4] = {2, 4, 5, 8};
    double n2[4] = {1, 0, 4, 6};
    double n3[4];
    foo(n1, n2, n3, 4);
    output(n3, 4);
    return 0;
}

void foo(double *n1, double *n2, double *n3, int size) {
    for (int i = 0; i < size; ++i)
        n3[i] = SUM(n1[i], n2[i]);
}

void output(double *t, int n) {
    for (int i = 0; i < n; ++i)
        printf("%.0lf ", t[i]);
    printf("\n");
}