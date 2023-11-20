#include <stdio.h>

void read_first_word(char *str);

int main(void) {
    char res[100];
    read_first_word(res);
    printf("%s\n", res);
    return 0;
}

void read_first_word(char *str) {
    char ch; 
    int i = 0;
    ch = getchar();
    while (ch == ' ') ch = getchar();
    while (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
}