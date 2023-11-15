#include <stdio.h>

int main(void) {
    float cash_s = 1000000, cash_h = 1000000;
    int year_s = 0, year_h = 0;
    for (; cash_s > 100000 && cash_h > 100000;) {
        cash_s -= 100000;
        cash_h -= 100000;
        cash_s += 1000000 * 0.08;
        cash_h *= 1.08;
        if (cash_s > 100000) ++year_s;
        if (cash_h > 100000) ++year_h;
    }
    printf("With simple: %d\n", year_s);
    printf("With hard: %d", year_h);
    return 0;
}