#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int bintoint(char *);

int main(void) {
    printf("%d\n", bintoint("01001001"));
}

int bintoint(char *bin) {
    int num = atoi(bin);
    int res = 0;
    for (int i = 0; num > 0; ++i) {
        res += (num % 10) * (int)pow(2, i);
        num /= 10;
    }
    return res;
}