#include <stdio.h>

int main(void) {
    char ch;
    printf("Begin input random symbols: ");
    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case '\n':
                printf("\\n");
                break;
            case ' ':
                printf("SPACE");
                break;
            case 4:
                printf("^D");
                break;
            default:
                putchar(ch);
                break;
        }
        printf("-%d\n", (int)ch);
    }
    return 0;
}