#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void input(int* up, int* down);
void lenght(int* l1, int* l2, int* l3, int up);
void output(int up, int down);

int main(void) {
    int up, down;
    input(&up, &down);
    output(up, down);

    return 0;
}

void input(int* up, int* down) {
    printf("Input upper limit of table: ");
    
    while (scanf("%d", up) != 1)
    {
        printf("Please, input integer value: ");
        fflush(stdin);
    }
    printf("Input down limit of table: ");
    while (1)
    {
        if (scanf("%d", down) != 1) {
            printf("Please, input integer value: ");
            fflush(stdin);
            continue;
        } else if (*down < *up) {
            printf("Please, input down limit bigger than upper or equil: ");
            fflush(stdin);
            continue;
        }
        break;
    }
}

void output(int up, int down) {
    int l1, l2, l3;
    lenght(&l1, &l2, &l3, down);
    for (; up <= down; ++up) {
        for (int i = 0; i < l1+l2+l3+10; ++i) printf("-");
        printf("\n");
        //printf("\n| %*c | %*c | %*c |\n", l1, ' ', l2, ' ', l3, ' ');
        printf("| %*d | %*d | %*d |\n", l1, up, l2, up*up, l3, up*up*up);
        //printf("| %*c | %*c | %*c |\n", l1, ' ', l2, ' ', l3, ' ');
    }
    for (int i = 0; i < l1+l2+l3+10; ++i) printf("-");
}

void lenght(int* l1, int* l2, int* l3, int up) {
    *l1 = 0, *l2 = 0, *l3 = 0;
    *l1 = floor(log10(abs(up))) + 1;
    *l2 = floor(log10(abs(up*up))) + 1;
    *l3 = floor(log10(abs(up*up*up))) + 1;
}