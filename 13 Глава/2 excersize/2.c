#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp_s, *fp_c;

    if ((fp_s = fopen(argv[1], "rb")) == NULL || (fp_c = fopen(argv[2], "wb")) == NULL) {
        printf("Can't open files", argv[1]);
    } else {
        fseek(fp_s, 0L, SEEK_SET);
        // fflush(fp_c);
        //fseek(fp_c, 0L, SEEK_SET);
        char ch = getc(fp_s);
        while (ch != EOF) {
            putc(ch, fp_c);
            ch = getc(fp_s);
        }
        fwrite("(!COPIED!)", sizeof(char), 10, fp_c);
        fclose(fp_s), fclose(fp_c);
    }
    return 0;
}