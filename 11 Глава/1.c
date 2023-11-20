#include <stdio.h>
#define N 12

void input(int, char *);
void output(char *, int);

int main(void) {
    printf("Input symbols: ");
    char symbols[N];
    input(N, symbols);
    output(symbols, N);
    return 0;
}

void input(int n, char *symbols) {
    for (int i = 0; i < n; ++i) {
        symbols[i] = getchar();
    }
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