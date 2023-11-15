#include <stdio.h>

int main(void) {
    char str[255];
    printf("Input string: ");
    scanf("%s", str);
    int i = 0;
    for (; str[i] != '\0'; ++i);
    --i;
    for (; i >= 0; --i) {
        printf("%c", str[i]);
    }
    return 0;
}