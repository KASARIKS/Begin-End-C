#include <stdio.h>
#define MAX_SIZE 1000

void input(char str[MAX_SIZE]);
int mystrlen(char *);
void no_spaces(char str[MAX_SIZE]);
void start(void);

int main(void) {
    start();
    return 0;
}

void input(char str[MAX_SIZE]) {
    printf("Input string(or nothing for exit): ");
    char ch;
    int i = 0;
    for (i = 0; (ch = getchar()) != '\n'; ++i) {
        str[i] = ch;
    };
    str[i] = '\0';
    fflush(stdin);
}

void start(void) {
    while (1) {
        char str[MAX_SIZE];
        input(str);
        if (mystrlen(str) <= 0) {
            break;
        }
        no_spaces(str);
        printf("New string: %s\n", str);
    }
}

int mystrlen(char *str) {
    int len = 0;
    for (; str[len] != '\0'; ++len);
    return len;
}

void no_spaces(char str[MAX_SIZE]) {
    char tmp;
    int step = 0;
    int i;
    for (i = 0; i < mystrlen(str); ++i) {
        // printf("'%c' '%c'\n", str[i - 1], str[i]);
        // printf("%s\n", str);
        // printf("\n");
        str[i - step] = str[i];
        if (str[i] == ' ') ++step;
    }
    str[i - step] = '\0';
}