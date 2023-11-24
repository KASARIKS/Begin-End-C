#include <stdio.h>
#include <ctype.h>

int main(void) {
    char input_file[80], output_file[80];
    printf("Input source file name: ");
    scanf("%s", input_file);
    printf("Input output file name: ");
    scanf("%s", output_file);

    FILE *fp_s, *fp_o;
    if ((fp_s = fopen(input_file, "r")) == NULL || (fp_o = fopen(output_file, "w")) == NULL) {
        printf("Can't open files!\n");
    } else {
        char ch;
        while ((ch = getc(fp_s)) != EOF) {
            putc(toupper(ch), fp_o);
        }
    }
    return 0;
}