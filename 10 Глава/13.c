#include <stdio.h>

#define N 3
#define M 5

void input(double[N][M]);
void count_average_all_strs(double[N][M], double[N]);
void count_average_all(double[N], double*);
void find_max(double[N][M], double*);
void output(double[N][M], double[N], double, double);

int main(void) {
    // Data
    double arr[N][M];
    double averages[N] = {0, 0, 0};
    double average = 0, max = 0;

    input(arr);
    count_average_all_strs(arr, averages);
    count_average_all(averages, &average);
    find_max(arr, &max);
    output(arr, averages, average, max);
    return 0;
}

void input(double str[N][M]) {
    printf("Input 3 sequince with 5 elements: ");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            while (scanf("%lf", &str[i][j]) != 1) {
                printf("WRONG INPUT!\n");
                printf("Input 3 sequince with 5 elements: ");
                fflush(stdin);
            }
        }
    }
}

void count_average_all_strs(double arr[N][M], double averages[N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            averages[i] += arr[i][j];
        }
        averages[i] /= M;
    }
}

void count_average_all(double averages[N], double *average) {
    *average = 0;
    for (int i = 0; i < N; ++i) *average += averages[i];
    *average /= N;
}

void find_max(double arr[N][M], double *max) {
    *max = arr[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (*max < arr[i][j]) *max = arr[i][j];
        }
    }
}

void output(double arr[N][M], double averages[N], double average, double max) {
    // arr
    printf("Array: \n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }

    // averages
    printf("Averages: \n");
    for (int i = 0; i < N; ++i)
        printf("%lf ", averages[i]);
    printf("\n");

    // average, max
    printf("Average: %lf\n", average);
    printf("Max: %lf\n", max);
}