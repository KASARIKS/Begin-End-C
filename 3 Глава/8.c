#include <stdio.h>

int main(void) {
    float pints, cups, unts, folks, tea_folks;
    printf("Input number of cups: ");
    scanf("%f", &cups);
    pints = cups / 2;
    cups = pints * 2;
    unts = cups * 8;
    folks = unts * 2;
    tea_folks = folks * 3;
    printf("pints: %f\ncups: %f\nunts: %f\nfolks: %f\ntea_folks: %f", pints, cups, unts, folks, tea_folks);

    return 0;
}