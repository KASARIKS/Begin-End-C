#include <stdio.h>

int main(void) {
    float num;

    printf("Input float number: ");
    scanf("%f", &num);
    printf("Writing with fixed comma: %.6f\n", num);
    printf("Exponent form of writing: %e\n", num);
    printf("Double bit float: %a", num);

    return 0;
}