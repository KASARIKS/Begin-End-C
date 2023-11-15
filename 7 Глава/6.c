#include <stdio.h>

int main(void) {
    char ch, ch_last;
    int count_ei = 0;
    while ((ch = getchar()) != '#') {
        if (ch == 'i' && ch_last == 'e') ++count_ei;
        ch_last = ch;
    }
    printf("ei entering number: %d", count_ei);
    return 0;
}