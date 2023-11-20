#include <stdio.h>

int mystrlen(char *);
char* string_in(char *, char *);
void driver(void);

int main(void) {
    driver();
    return 0;
}

void driver(void) {
    char targets[8][10] = {"abc", "abc", "abc", "abc", "dfg", "abcd", "", ""};
    char sources[8][10] = {"abc", "dabc", "abcd", "dabcd", "abc", "abc", "abc", ""};
    for (int i = 0; i < 8; ++i) {
        printf("%s, %s = %s\n", sources[i], targets[i], string_in(sources[i], targets[i]));
    }
}

char* string_in(char *s1, char *s2) {
    // If empty strings
    if (mystrlen(s1) == 0 && mystrlen(s2) == 0 || mystrlen(s2) == 0) return s2;

    // Main algorithm
    int count_sequence_sym = 0;
    for (int i = 0; i < mystrlen(s1); ++i) {
        if (s1[i] == s2[count_sequence_sym]) {
            if (count_sequence_sym == mystrlen(s2) - 1) return &s1[i] - count_sequence_sym;
            ++count_sequence_sym;
        } else {
            count_sequence_sym = 0;
        }
    }

    return NULL;
}

int mystrlen(char *str) {
    int len = 0;
    for (; str[len] != '\0'; ++len);
    return len;
}