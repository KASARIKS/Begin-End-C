#include <stdio.h>

void copy_arr(double[], double[], int);
void output(double [5][5], int);

int main(void) {
    double nums_s[] = {1, 2, 3, 4, 5};
    double nums_hub[5][5];
    for (int i = 0; i < 5; ++i) {
        copy_arr(nums_hub[i], nums_s, 5);
    }
    output(nums_hub, 5);

    return 0;
}

void copy_arr(double t[], double s[], int n) {
    for (int i = 0; i < n; ++i) {
        t[i] = s[i];
    }
}

void output(double t[5][5], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%.0lf ", t[i][j]);
        printf("\n");
    }
        
    printf("\n");
}