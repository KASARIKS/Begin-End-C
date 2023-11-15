#include <stdio.h>

int main(void) {
    char let = 'A';

    for (int str = 0; str <= 5; ++str) {
        for (int sym = 0; sym <= str; ++sym)
            printf("%c", let++);
        printf("\n");
    }
    return 0;
}