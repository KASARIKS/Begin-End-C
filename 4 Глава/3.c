#include <stdio.h>

int main(void) {
    float num;
    printf("Input real number: ");
    scanf("%f", &num);
    printf("Input is %.1f or %.1e\n", num, num);
    printf("Input is %+.3f or %.3E", num, num);

    return 0;
}