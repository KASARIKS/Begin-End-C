#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int r1 = (int)atoi(argv[1]), r2 = (int)atoi(argv[2]);
    printf("~%d ~%d = %d %d\n", r1, r2, ~r1, ~r2);
    printf("%d & %d = %d\n", r1, r2, r1&r2);
    printf("%d | %d = %d\n", r1, r2, r1|r2);
    printf("%d ^ %d = %d\n", r1, r2, r1^r2);
    return 0;
}