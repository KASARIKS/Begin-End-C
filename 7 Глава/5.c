#include <stdio.h>

int main(void) {
    char ch;
    while ((ch = getchar()) != '#')
    {
        switch (ch) {
            case '.':
                printf("!");
                break;
            case '!':
                printf("!!");
                break;
            default:
                printf("%c", ch);
        }
    }
    return 0;
}