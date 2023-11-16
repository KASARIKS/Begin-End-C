#include <stdio.h>

int main(void) {
    int count = 0;
    char ch;
    printf("Begin input random symbols: ");
    while ((ch = getchar()) != EOF) {
        ++count;
    }
    printf("%d", count);
    return 0;
}