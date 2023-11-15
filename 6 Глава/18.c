#include <stdio.h>
#define DANBAR 150

int main(void) {
    int N = 5;
    for (int week = 1; N <= DANBAR; ++week) {
        N -= week;
        N *= 2;
        printf("Week %d: %d\n", week, N);
    }
}