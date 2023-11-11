#include <stdio.h>

void print_quad(double n) {
    printf("%lf", n * n);
}

int main(void) {
    printf("Input real number: ");
    double n;
    scanf("%lf", &n);
    print_quad(n);
    return 0;
}