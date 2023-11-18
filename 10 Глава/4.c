#include <stdio.h>
void driver(void);
int max(double *, int);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    double nums[] = {1, 2, 3, 4, 5};
    printf("{1, 2, 3, 4, 5} = %d\n", max(nums, 5));
    double nums2[] = {42, -10, -0, 0, 1000, 42, 12, -1000};
    printf("{42, -10, -0, 0, 1000, 42, 12, -1000} = %d\n", max(nums2, 8));
}

int max(double *nums, int n) {
    int i_max = 0;
    for (int i = 1; i < n; ++i)
        if (nums[i] > nums[i_max]) i_max = i; 

    return i_max;
}