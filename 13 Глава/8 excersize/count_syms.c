#include "count_syms.h"
#include <stdio.h>

int count_syms(char *name, char sym) {
    int count = 0;
    FILE *fp;
    if ((fp = fopen(name, "r")) == NULL) return -1;
    char ch;
    while ((ch = getc(fp)) != EOF) {
        if (ch == sym) ++count;
    }
    return count;
}