#include <stdio.h>

int main(void) {
    int n;
    printf("Input integer number: ");
    scanf("%d", &n);
    for (int i = 0; i <= 10; ++i) {
        printf("%d\n", n++);
    }
    return 0;
}