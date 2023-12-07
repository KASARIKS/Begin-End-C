#include "stack.h"
#include <stdio.h>

void s_gets(Stack *string);

int main(void) {
    Stack string;
    printf("Input string: ");
    s_gets(&string);
    printf("Your string reversed: ");
    while (string.size > 0) {
        printf("%c", Pop(&string));
    }
    printf("\n");
    return 0;
}

void s_gets(Stack *string) {
    char ch;
    while ((ch = getchar()) != '\n') {
        Push(string, ch);
    }
}