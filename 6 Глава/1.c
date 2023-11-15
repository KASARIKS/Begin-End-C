#include <stdio.h>

int main(void) {
    char alphabet[27] = "qwertyuiopasdfghjklzxcvbnm\0";
    printf("%s", alphabet);
    return 0;
}