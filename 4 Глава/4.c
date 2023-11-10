#include <stdio.h>

int main(void) {
    float height;
    char name[30];
    printf("Input height in sm: ");
    scanf("%f", &height);
    printf("Input name: ");
    scanf("%s", name);
    printf("%s, your height is %.3f metres", name, height / 100);
    return 0;
}