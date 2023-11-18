#include <stdio.h>

void chline(char, int, int);
void driver(void);

int main(void) {
    driver();
}

void driver(void) {
    chline('a', 0, 10);
    chline('a', 0, 0);
    chline('a', 0, 1);
    chline('a', 2, 2);
    chline('a', 2, 5);
}

void chline(char c, int i, int j) {
    for (int d = 0; d < i; ++d) printf(" ");
    for (; i < j; ++i) printf("%c", c);
    printf("\n");
}