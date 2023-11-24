#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        FILE *fp;
        if ((fp = fopen(argv[i], "r")) != NULL) {
            char ch;
            while ((ch = getc(fp)) != EOF) {
                putchar(ch);
            }
            printf("\n");
        }
    }
    return 0;
}