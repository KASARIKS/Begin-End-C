#include <stdio.h>

int main(void) {
    float height;
    printf("Input height in centimetres: ");
    scanf("%f", &height);
    while (height > 0) {
        printf("Height in centimetres: %f\n", height);
        printf("Height in foots: %f\n", height * 0.32);
        printf("Height in dumes: %f\n", height * 0.39);
        printf("Input height in centimetres: ");
        scanf("%f", &height);
    }
    return 0;
}