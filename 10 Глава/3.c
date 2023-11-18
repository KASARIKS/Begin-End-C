#include <stdio.h>
#include <limits.h>
void driver(void);
int max(int *, int n);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    int nums[] = {1, 2, 3, 4, 5};
    printf("{1, 2, 3, 4, 5} = %d\n", max(nums, 5));
    int nums2[] = {42, -10, -0, 0, 1000, 42, 12, -1000};
    printf("{42, -10, -0, 0, 1000, 42, 12, -1000} = %d\n", max(nums2, 8));
}

int max(int *nums, int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > max) max = nums[i];   
    }
    return max;
}