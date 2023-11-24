#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char *str = malloc(sizeof(char) * 1000);
    printf("Input file name: ");
    scanf("%s", str);

    if ((fp = fopen(str, "r")) == NULL) {
        printf("Can't open %s\n", str);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\n");
    printf("File %s has %lu symbols\n", str, count);
    free(str);
    return 0;
}