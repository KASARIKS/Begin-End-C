#include <stdio.h>

int main(void) {
    printf("Input symbols: ");
    char ch;
    int i = 0;
    for (; (ch = getchar()) != '#';) {
        if (ch != '\n') printf("%c-%d", ch, ch);
        if (i % 8 == 0) printf("\n");
        ++i;
    }
    return 0;
}