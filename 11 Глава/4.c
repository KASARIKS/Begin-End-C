#include <stdio.h>

void read_first_word(char *str, int max_size);

int main(void) {
    char res[100];
    read_first_word(res, 20);
    printf("%s\n", res);
    return 0;
}

void read_first_word(char *str, int max_size) {
    char ch; 
    int i = 0;
    ch = getchar();
    while (ch == ' ') ch = getchar();
    while (i < max_size && (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')) {
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
}