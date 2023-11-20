#include <stdio.h>

char *mystrcpy(char *s1, char *s2, int n);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    char targets[5][3];
    char sources[5][10] = {"abc", "ab", "abcd", "a", ""};
    
    for (int i = 0; i < 5; ++i)
        printf("%.3s, target = %.3s\n", targets[i], mystrcpy(targets[i], sources[i], 3));
}

char *mystrcpy(char *s1, char *s2, int n) {
    for (int i = 0; i < n; ++i)
        s1[i] = s2[i];
    return s1;
}