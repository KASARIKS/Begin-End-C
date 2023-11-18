#include <stdio.h>

void copy_ptrs(double*, double*, double*);
void output(double *, int);

int main(void) {
    double nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double nums_small[3];
    copy_ptrs(nums_small, nums + 2, nums + 5);
    output(nums_small, 3);
    return 0;
}

void copy_ptrs(double *t, double *s, double *s_last) {
    while (*s != *s_last) {
        *t = *s;
        ++t, ++s;
    }
}

void output(double *t, int n) {
    for (int i = 0; i < n; ++i)
        printf("%.0lf ", t[i]);
    printf("\n");
}