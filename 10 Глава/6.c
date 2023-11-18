#include <stdio.h>

void swap(double *, double *);
void invert(double *, int);
void output(double *, int);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    double nums[] = {1, 2, 3, 4, 5};
    invert(nums, 5);
    printf("{1, 2, 3, 4, 5} = ");
    output(nums, 5);
    double nums2[] = {42, -10, -0, 0, 1000, 42, 12, -1000};
    invert(nums2, 8);
    printf("{42, -10, -0, 0, 1000, 42, 12, -1000} = ");
    output(nums2, 8);
}

void invert(double *nums, int size) {
    int is_chet = size % 2 == 0;
    for (int i = 0; i < size - (size / 2) + is_chet; ++i) {
        swap(&nums[i], &nums[size - i - 1]); 
    }
}

void swap(double *a, double *b) {
    int tmp;
    tmp = *a;
    *a = *b; 
    *b = tmp;
}

void output(double *t, int n) {
    for (int i = 0; i < n; ++i)
        printf("%.0lf ", t[i]);
    printf("\n");
}