#include <stdio.h>

int mystrlen(char *);
void swap(char *, char *);
void strinv(char *);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    char sources[5][10] = {"abcde", "abcdef", "d", "df", ""};
    for (int i = 0; i < 5; ++i) {
        printf("\"%s\" = ", sources[i]);
        strinv(sources[i]);
        printf("\"%s\"\n", sources[i]);
    }
}

int mystrlen(char *str) {
    int len = 0;
    for (; str[len] != '\0'; ++len);
    return len;
}

void strinv(char *str) {
    for (int i = 0; i < mystrlen(str) / 2; ++i) {
        swap(&str[i], &str[mystrlen(str) - i - 1]);
    }
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b, *b = tmp;
}