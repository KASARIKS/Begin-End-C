#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 8

void input(double *a, double *b);
void output(double *a, double *b);

int main(void) {
    double *a = (double*)malloc(sizeof(double)* SIZE), *b = (double*)malloc(sizeof(double)* SIZE);
    input(a, b);
    output(a, b);
    free(a), free(b);
    return 0;
}

void output(double *a, double *b) {
    int* lengths = (int*)malloc(sizeof(int)*SIZE);
    for (int i = 0; i < SIZE; ++i) {
        lengths[i] = floor(log10(abs(b[i]))) + 1 + 7;
        for (int tir = 0; tir < lengths[i] + 2; ++tir) { printf("-"); }
    }
    for (int tir = 0; tir < SIZE; ++tir) { printf("-"); }
    printf("+\n");

    for (int i = 0; i < SIZE; ++i) {
        printf("| %*lf ", lengths[i], a[i]);
    }
    printf("|\n");

    for (int i = 0; i < SIZE; ++i) {
        for (int tir = 0; tir < lengths[i] + 2; ++tir) { printf("-"); }
    }
    for (int tir = 0; tir < SIZE; ++tir) { printf("-"); }
    printf("+\n");

    for (int i = 0; i < SIZE; ++i) {
        printf("| %*lf ", lengths[i], b[i]);
    }
    printf("|\n");

    for (int i = 0; i < SIZE; ++i) {
        for (int tir = 0; tir < lengths[i] + 2; ++tir) { printf("-"); }
    }
    for (int tir = 0; tir < SIZE; ++tir) { printf("-"); }
    printf("+\n");
    free(lengths);
}

void input(double *a, double *b) {
    printf("Input real number 1: ");
    while (scanf("%lf", &a[0]) != 1) {
        printf("This isn't real number: ");
        fflush(stdin);
    }
    b[0] = a[0];
    for (int i = 1; i < SIZE; ++i) {
        printf("Input real number %d: ", i + 1);
        while (scanf("%lf", &a[i]) != 1) {
            printf("This isn't real number: ");
            fflush(stdin);
        }
        b[i] = b[i - 1] + a[i];
    }
}