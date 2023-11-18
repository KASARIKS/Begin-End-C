#include <stdio.h>

void foo(char, int, int);

int main(void) {
    int x, y;
    printf("Input 2 integer numbers separated by space: ");
    while (scanf("%d %d", &x, &y) != 2) {
        printf("WRONG INPUT!\n");
        printf("Input 2 integer numbers separated by space: ");
        fflush(stdin);
    }
    foo('@', x, y);
    return 0;
}

void foo(char ch, int x, int y) {
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            printf("%c", ch);
        }
        printf("\n");
    }
}