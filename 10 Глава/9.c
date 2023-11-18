#include <stdio.h>
#define N 3
#define M 5
void copy_arr(double[N][M], double[N][M]);
void output(double[N][M]);

int main(void) {
    double arr[N][M] = {
        {1, 2, 3, 4, 5},
        {5, 6, 7, 8, 9},
        {9, 1, 2, 3, 4}
    };
    double copy[N][M];
    copy_arr(arr, copy);
    output(copy);
    return 0;
}

void copy_arr(double source[N][M], double target[N][M]) {
    for (int y = 0; y < N; ++y) 
        for (int x = 0; x < M; ++x)
            target[y][x] = source[y][x];
}

void output(double t[N][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            printf("%.0lf ", t[i][j]);
        printf("\n");
    }
        
    printf("\n");
}