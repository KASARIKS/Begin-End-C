#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void choose(int *nums, size_t size, int count_choosings) {
    srand(time(NULL));
    int *was_choosed_nums = (int*)malloc(sizeof(int)*count_choosings);
    int was_choosed = 0;
    for (int i = 0; i < count_choosings; ++i) {
        int num = nums[rand() % size];
        int j;
        for (j = 0; j < i; ++j) {
            if (was_choosed_nums[j] == num) {
                was_choosed = 1;
                break;
            }
        }
        if (was_choosed) {
            --i;
            was_choosed = 0;
        }
        else {
            was_choosed_nums[j] = num;
            printf("%d ", num);
        }
    }
    free(was_choosed_nums);
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    choose(nums, 9, 8);
    return 0;
}