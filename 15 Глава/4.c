#include <stdio.h>
#include <stdlib.h>

char* bintodec(int num, int *i) {
    char *dec = (char*)malloc(sizeof(char)*100);
    for (*i = 0; num > 0; ++(*i)) { 
        dec[*i] = (num % 2) + 48;
        num /= 2;
    }
    return dec;
}

int foo(int val, int pos) {
    int i;
    char *binary = bintodec(val, &i);
    int res = binary[i - pos] == '1';
    free(binary);
    return res;
}

int main(void) {
    int num = 25, pos = 2;
    printf("%d with position %d is %d.\n", num, pos, foo(num, pos));
    return 0;
}