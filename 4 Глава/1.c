#include <stdio.h>

int main(void) {
    printf("Input first and last name: ");
    char last[30], first[30];
    scanf("%s %s", first, last);
    printf("%s %s", last, first);
    return 0;
}