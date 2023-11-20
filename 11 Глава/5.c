#include <stdio.h>

int *custom_strchr(char *, char);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    char arr[] = {'b', 'a', 'c', 'd'};
    for (int i = 0; i < 3; ++i) {
        printf("abc, %c = %c\n", arr[i], *custom_strchr("abc", arr[i]));
    }
    printf("abc, %c = %d", arr[3], *custom_strchr("abc", arr[3]));
}

int *custom_strchr(char *str, char ch) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ch) {
            char *ch_p = &ch;
            return (int*)ch_p;
        }
    }
    int var = 0;
    int *pr = &var;
    return pr;
}