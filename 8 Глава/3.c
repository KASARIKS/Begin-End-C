#include <stdio.h>

int main(void) {
    char ch;
    int prop = 0, strot = 0, ost = 0;
    while ((ch = getchar()) != EOF) {
        if ((int)ch >= 'A' && (int)ch <= 'Z') ++prop;
        else if ((int)ch >= 'a' && (int)ch <= 'z') ++strot;
        else ++ost;
    }
    printf("Big letters: %d\n", prop);
    printf("Small letters: %d\n", strot);
    printf("Another symbols: %d\n", ost);
    return 0;
}