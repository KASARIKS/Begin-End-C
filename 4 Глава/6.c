#include <stdio.h>
#include <string.h>

int main(void) {
    char first_n[30], last_n[30];
    printf("Input first and last name: ");
    scanf("%s %s", first_n, last_n);
    int f_l = strlen(first_n), l_l = strlen(last_n);
    // printf("%10s %10s\n%10d %10d", first_n, last_n, f_l, l_l);
    printf("%s %s\n%*d %*d\n", first_n, last_n, f_l, f_l, l_l, l_l);
    printf("%s %s\n%-*d %-*d", first_n, last_n, f_l, f_l, l_l, l_l);
    return 0;
}