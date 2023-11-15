#include <stdio.h>

int is_simple(int n);

int main(void) {
    // Input
    int number;
    printf("Input simple positive number: ");
    while (scanf("%d", &number) != 1) {
        printf("Wrong input!\n");
        printf("Input simple positive number: ");
        fflush(stdin);
    }

    // Output
    for (int i = 1; i <= number; ++i) 
        if (is_simple(i)) printf("%d ", i);

    return 0;
}

int is_simple(int n) {
    for (int i = 2; i < n / 2 + 1; ++i) 
        if (n % i == 0) return 0;
    return 1;
}