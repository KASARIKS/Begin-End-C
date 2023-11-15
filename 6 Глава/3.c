#include <stdio.h>

int main(void) {
    for (int str = 0; str <= 5; ++str) {
        for (int sym = 0; sym <= str; ++sym)
            printf("%c", 'F' - sym);
        printf("\n");
    }
    return 0;
}