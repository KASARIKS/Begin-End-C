#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1000

void input(char *str);
int words(const char *sentence);
int is_syms(const char sentence);
void count(int *elems, char *str);

int main(void) {
    char str[MAXLEN];
    // Words, small letters, big letters, number of symbols prep, number of digits
    int elems[] = {0, 0, 0, 0, 0};
    input(str);
    count(elems, str);
    printf("Words: %d\n", elems[0]);
    printf("Small letters: %d\n", elems[1]);
    printf("Big letters: %d\n", elems[2]);
    printf("Number of symbols: %d\n", elems[3]);
    printf("Number of digits: %d\n", elems[4]);
    return 0;
}

void input(char *str) {
    char ch;
    int i = 0;
    ch = getchar();
    for (; ch != '\n' && ch != EOF; ++i) {
        str[i] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    fflush(stdin);
}

int words(const char *sentence)
{
    int counted = 0; // result
    char str[MAXLEN];
    strcpy(str, sentence);

    // state:
    const char* it = str;
    int inword = 0;

    do switch(*it) {
        case '\0': 
        case ' ': case '\t': case '\n': case '\r': // TODO others?
            if (inword) { inword = 0; counted++; }
            break;
        default: inword = 1;
    } while(*it++);

    return counted;
}

void count(int *elems, char *str) {
    elems[0] = words(str);
    for (int i = 0; i < strlen(str); ++i) {
        if (islower(str[i])) elems[1]++;
        else if (isupper(str[i])) elems[2]++;
        else if (is_syms(str[i])) elems[3]++;
        else if (isdigit(str[i])) elems[4]++;
    }
}

int is_syms(const char sentence) { 
    const char mas[7] = {'.', ',', '!', '?', ';', ':', '-'};
    for (int i = 0; i < 7; ++i) 
        if (mas[i] == sentence) return 1;
    return 0;
}