#include <stdio.h>

int main(void) {
    int height;
    printf("Input height in cm: ");
    scanf("%d", &height);
    printf("Height in dm: %f", height / 2.54);
    return 0;
}