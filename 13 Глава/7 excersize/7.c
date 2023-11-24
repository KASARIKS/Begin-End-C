#include <stdio.h>

int main(void) {
    // Input data
    char first_name[80], second_name[80];
    printf("Input 2 files names separated by space: ");
    scanf("%s %s", first_name, second_name);

    // Opening files
    FILE *f1, *f2;
    if ((f1 = fopen(first_name, "r")) == NULL || (f2 = fopen(second_name, "r")) == NULL) {
        printf("Can't open files\n");
    } else {
        char ch1, ch2;
        while (ch1 != EOF && ch2 != EOF) {
            printf("1, 2. ");
            ch1 = getc(f1);
            while (ch1 != '\n' && ch1 != EOF) {
                putchar(ch1);
                ch1 = getc(f1);
            }
            printf(" | ");
            ch2 = getc(f2);
            while (ch2 != '\n' && ch2 != EOF) {
                putchar(ch2);
                ch2 = getc(f2);
            }
            printf("\n");
        }
    }

    fclose(f1), fclose(f2);
}