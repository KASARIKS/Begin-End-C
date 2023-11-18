#include <stdio.h>

void copy_arr(double[], double[], int);
void copy_ptr(double*, double*, int);
void copy_ptrs(double*, double*, double*);
void output(double*, int);

int main(void) {
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5], target2[5], target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    printf("target1: ");
    output(target1, 5);
    printf("target2: ");
    output(target2, 5);
    printf("target3: ");
    output(target3, 5);
    return 0;
}

void output(double *t, int n) {
    for (int i = 0; i < n; ++i)
        printf("%.1lf ", t[i]);
    printf("\n");
}

void copy_arr(double t[], double s[], int n) {
    for (int i = 0; i < n; ++i) {
        t[i] = s[i];
    }
}

void copy_ptr(double *t, double *s, int n) {
    for (int i = 0; i < n; ++i) {
        *(t + i) = *(s + i);
    }
}

void copy_ptrs(double *t, double *s, double *s_last) {
    while (s != s_last) {
        *t = *s;
        ++t, ++s;
    }
}