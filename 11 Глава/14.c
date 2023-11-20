#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char *ptr;
    double num = strtod(argv[1], &ptr);
    printf("%lf^%d = %lf", num, atoi(argv[2]), pow(num, atoi(argv[2])));
    return 0;
}