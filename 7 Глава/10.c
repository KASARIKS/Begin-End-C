#include <stdio.h>

void input(int *categorie, float *salary);

int main(void) {
    // Alone, Family lead, Married and farm together, Married and farm alone.
    const float taxes[] = { 17850, 23900, 29750, 14875 };
    int categorie;
    float salary;
    input(&categorie, &salary);
    while (categorie >= 1 && categorie <= 4 && salary != 0) {
        printf("Summary of tax: %f\n", 0.15 * taxes[categorie - 1] + 0.28 * (salary > taxes[categorie - 1] ? salary - taxes[categorie - 1] : 0));
        input(&categorie, &salary);
    }
    return 0;
}

void input(int *categorie, float *salary) {
    printf("Input categorie from 1 to 4 and salary with integer number separated by space(another for exit): ");
    if (scanf("%d %f", categorie, salary) != 2) *categorie = 0, *salary = 0;
    fflush(stdin);
}