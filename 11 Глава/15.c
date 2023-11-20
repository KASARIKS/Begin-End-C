#include <stdio.h>
#include <ctype.h>
#include <string.h>

int not_need(char *str);
int atoi(char *str);

int main(void) {
    printf("%d\n", atoi("1230"));
    return 0;
}

int atoi(char *str) {
    if (not_need(str)) {
        return 0;
    }
    int res = 0; 
    int tens = 1; 
    for (int i = strlen(str) - 1; i > 0; --i) {
        res += (str[i] - 48) * tens;
        tens *= 10;
    }

    if (str[0] == '-') res *= -1;
    else res += (str[0] - 48) * tens;

    return res;
}

int not_need(char *str) {
    if (!isdigit(str[0]) && str[0] != '-') return 1;
    for (int i = 1; i < strlen(str); ++i) {
        if (!isdigit(str[i])) return 1;
    }

    return 0;
}