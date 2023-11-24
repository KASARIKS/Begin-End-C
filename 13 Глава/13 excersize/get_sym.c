#include "get_sym.h"
char get_sym(FILE *fp) {
    char ch;
    fread(&ch, sizeof(char), 1, fp);
    return ch;
}