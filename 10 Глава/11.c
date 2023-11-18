#include <stdio.h>

#define N 3
#define M 5

void output(int[][M], int);
void twice_arr(int[][M], int);

int main(void) {
    int arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 6, 7, 8, 9},
        {9, 1, 2, 3, 4}
    };
    output(arr, N);
    twice_arr(arr, N);
    output(arr, N);
    return 0;
}

void output(int t[][M], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < M; ++j)
            printf("%-2d ", t[i][j]);
        printf("\n");
    }
        
    printf("\n");
}

void twice_arr(int t[][M], int rows) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < M; ++j) 
            t[i][j] *= 2;
}