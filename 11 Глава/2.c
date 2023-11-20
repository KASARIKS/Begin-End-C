#include <stdio.h>
#define N 12

int input(int, char *);
void output(char *, int);

int main(void) {
    printf("Input symbols: ");
    char symbols[N];
    int n = input(N, symbols);
    output(symbols, n);
    return 0;
}

int input(int n, char *symbols) {
    int i;
    for (i = 0; i < n; ++i) {
        symbols[i] = getchar();
        if (symbols[i] == '\n' || symbols[i] == ' ' || symbols[i] == '\t') break;
    }
    return i;
}

void output(char *symbols, int size) {
    for (int i = 0; i < size; ++i) 
        if (symbols[i] == '\n') 
            printf("'\\n', ");
        else if (symbols[i] == '\t')
            printf("'\\t', ");
        else
            printf("'%c', ", symbols[i]);

    printf("\n");
}