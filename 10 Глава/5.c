#include <stdio.h>

void driver(void);
double max(double *, int);
double min(double *, int);
double foo(double *, int);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    double nums[] = {1, 2, 3, 4, 5};
    printf("{1, 2, 3, 4, 5} = %.0lf\n", foo(nums, 5));
    double nums2[] = {42, -10, -0, 0, 1000, 42, 12, -1000};
    printf("{42, -10, -0, 0, 1000, 42, 12, -1000} = %.0lf\n", foo(nums2, 8));
}

double foo(double *nums, int size) {
    return max(nums, size) - min(nums, size);
}

double max(double *nums, int n) {
    double max = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > max) max = nums[i];   
    }
    return max;
}

double min(double *nums, int n) {
    double min = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] < min) min = nums[i];   
    }
    return min;
}