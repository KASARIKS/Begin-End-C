#include <stdio.h>

void Fibonacci(int);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    Fibonacci(1);
    Fibonacci(2);
    Fibonacci(3);
    Fibonacci(4);
    Fibonacci(5);
    Fibonacci(6);
    Fibonacci(7);
    Fibonacci(8);
    Fibonacci(9);
    Fibonacci(10);
    Fibonacci(20);
}

void Fibonacci(int n) {
    printf("0 ");
    int a = 1, b = 1;
    int tmp;
    printf("%d %d ", a, b);
    for (int i = 3; i < n; ++i) {
        tmp = a;
        a = b;
        b += tmp;
        printf("%d ", b);
    }
    printf("\n");
}