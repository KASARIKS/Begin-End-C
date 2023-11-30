#include <stdio.h>
#include <stdlib.h>

// need to turn around string
char* bintodec(int num) {
    char *dec = (char*)malloc(sizeof(char)*100);
    for (int i = 0; num > 0; ++i) {
        dec[i] = (num % 2) + 48;
        num /= 2;
    }
    return dec;
}

int bits(int num) {
    char *dec = bintodec(num);
    int count_bits = 0;
    for (int i = 0; dec[i] != '\0'; ++i) {
        if (dec[i] == '1') ++count_bits;
    }
    free(dec);
    return count_bits;
}

int main(void) {
    int num = 12345;
    printf("%d = %d bits.\n", num, bits(num));
    return 0;
}