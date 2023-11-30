// Right move because, with left move no one bit isnt lost
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void custombinmove(char *num, int bits) {
    int last = strlen(num) - 1;
    for (int bit = 0; bit < bits; ++bit) {
        char tmp_digit = num[1];
        char tmp_digit2;
        num[1] = num[0];
        for (int digit = 1; digit < last; ++digit) {
            tmp_digit2 = num[digit + 1];
            num[digit + 1] = tmp_digit;
            tmp_digit = tmp_digit2;
        }
        num[0] = tmp_digit;
    }
}

int main(void) {
    char num_str[100];
    unsigned int num = 123456;
    itoa(num, num_str, 10);
    custombinmove(num_str, 13);
    printf("%d\n", atoi(num_str));
    return 0;
}