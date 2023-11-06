#include <stdio.h>

int main(void) {
    float year;
    printf("Input number of full years of your age: ");
    scanf("%f", &year);
    printf("Seconds: %.0f", year * 3.156 * 10e6);
    return 0;
}