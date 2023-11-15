#include <stdio.h>

int main(void) {
    int nums[8];
    for (int i = 1; i <= 8; ++i) {
        int n = 2;
        for (int j = 1; j < i; ++j) n *= 2;
        nums[i - 1] = n;
    }

    int i = 0;
    do
    {
        printf("%d ", nums[i++]);
    } while (i < 8);
    
    return 0;
}