#include <stdio.h>

void one_three();
void two();

int main(void) {
    printf("let's go:\n");
    one_three();
    printf("all right!");

    return 0;
}

void one_three() {
    printf("one\n");
    two();
    printf("three\n");
}

void two() {
    printf("two\n");
}