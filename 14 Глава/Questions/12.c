#include <stdio.h>
char* foo(char *p_ch, char ch) {
    p_ch = &ch;
    ++*p_ch;
    return p_ch;
}

int main(void) {
    char *(*p_foo)(char *p_ch, char ch) = foo;
    char ch = 'a';
    ch = *p_foo(&ch, ch);
    printf("%c\n", ch);
    return 0;
}