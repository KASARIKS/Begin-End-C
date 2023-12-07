#include <stdio.h>

int isIn(int *arr, int size, int num) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == num) return 1;
        else if (arr[mid] < num) left = mid + 1;
        else right = mid - 1;
    }

    return 0;
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 9, 12, 23, 23, 24};
    printf("%d\n", isIn(nums, 10, 11));
    return 0;
}