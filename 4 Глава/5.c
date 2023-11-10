#include <stdio.h>

int main(void) {
    float speed, size;
    printf("Input speed of downloading file in Mb/s: ");
    scanf("%f", &speed);
    printf("Input size of file in MB: ");
    scanf("%f", &size);
    printf("At download speed %.2f megabits in second file at size %.2f megabits download in %.2f seconds", speed, size, size * 8 / speed);
    return 0;
}