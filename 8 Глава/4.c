#include <stdio.h>

int main(void) {
    char ch;
    int count_let = 0, count_sym = 0;
    while ((ch = getchar()) != EOF) 
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) ++count_let;
        
    printf("%f", count_sym / count_let);
    return 0;
}