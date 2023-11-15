#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    printf("Input string: ");
    scanf("%s", str);
    for (int sym = strlen(str); sym >= 0; --sym) printf("%c", str[sym]);

    return 0;
}