#include "input_output.h"
#include "bones_throw.h"
#include <stdio.h>

int input(int *throw_count, int *sides, int *bones) {
    printf("Input number of throwings(one integer number or another for exit): ");
    if (scanf("%d", throw_count) != 1) {
        return 1;
    }
    fflush(stdin);
    printf("Input numbers of sides and bones(2 integer numbers separated by space or another for exit): ");
    if (scanf("%d %d", sides, bones) != 2) {
        return 1;
    }
    fflush(stdin);
    return 0;
}

void output(int throw_count, int sides, int bones) {
    printf("We have %d throwing %d bones with %d sides.\n", throw_count, sides, bones);
    for (int throw = 0; throw < throw_count; ++throw) {
        printf("%d ", bones_throw(sides, bones));
    }
    printf("\n");
}

void game(void) {
    int throw_count, sides, bones;
    while (!input(&throw_count, &sides, &bones))
    {
        output(throw_count, sides, bones);
    }
}