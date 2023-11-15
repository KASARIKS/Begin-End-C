#include <stdio.h>

void input(int* up, int* down);
int summary(int up, int down);

int main(void) {
    int up = 0, down = 1;
    while (up < down) {
        input(&up, &down);
        printf("Summary of quads of integer from %d to %d equil %d\n", up*up, down*down, summary(up, down));
    }

    return 0;
}

void input(int* up, int* down) {
    printf("Input integer upper and lower limits seperated by space(upper >= lower for exit): ");
    while (scanf("%d %d", up, down) != 2) {
        printf("There aren't 2 numbers or numbers at all: ");
        fflush(stdin);
    }
}

int summary(int up, int down) {
    int sum = 0;
    for (; up*up < down*down; ++up) {
        sum += up*up;
    }
    return sum;
}