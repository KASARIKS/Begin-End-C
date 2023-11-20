#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1000

void input(char str[MAXLEN]);
void output(char str[MAXLEN], char *choice);

int main(int argc, char *argv[]) {
    char str[MAXLEN];
    input(str);
    output(str, (argc > 1) ? argv[1] : "-p");
}

void input(char str[MAXLEN]) {
    char ch = getchar();
    int i = 0;
    for (; ch != '\n' && ch != EOF; ++i) {
        str[i] = ch;
        ch = getchar();
    }
    str[i] = '\0';
}

void output(char str[MAXLEN], char *choice) {
    if (!strcmp(choice, "-u")) for (int i = 0; i < strlen(str); ++i) str[i] = toupper(str[i]);
    else if (!strcmp(choice, "-l")) for (int i = 0; i < strlen(str); ++i) str[i] = tolower(str[i]);
    printf("%s", str);
}