#include <stdio.h>

int letter_code(int);
void input(int *);

int main(void) {
    int ch;
    input(&ch);
    while (ch != EOF) {
        if (letter_code(ch) > 0)
            printf("It's letter, code = %d\n\n", ch);
        else {
            printf("It isn't letter\n\n");
        }
        input(&ch);
    }
    return 0;
}

// 97 122, 65 90
int letter_code(int ch) {
    if ((ch > 'Z' || ch < 'A') && (ch > 'z' || ch < 'a')) return -1;
    else return ch;
}

void input(int *ch) {
    printf("Input symbol: ");
    *ch = getchar();
    fflush(stdin);
}