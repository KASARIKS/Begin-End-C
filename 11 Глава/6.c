#include <stdio.h>

int is_within(char *, char);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    char arr[] = {'b', 'a', 'c', 'd'};
    for (int i = 0; i < 4; ++i) {
        printf("abc, %c = %d\n", arr[i], is_within("abc", arr[i]));
    }
}

int is_within(char *str, char ch) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == ch) return ch;
    return 0;
}