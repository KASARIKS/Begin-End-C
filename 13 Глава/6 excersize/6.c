#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

int main() {
    FILE *in, *out; // Defining 2 pointes for FILE
    int ch;
    char name[LEN], input_name[LEN]; 
    int count = 0;
    printf("Input file name: ");
    scanf("%s", input_name);

    // Input configuration
    if ((in = fopen(input_name, "r")) == NULL) {
        fprintf(stderr, "Can't open the file\"%s\"\n", input_name);
        exit(EXIT_FAILURE);
    }

    // Output configuration
    strncpy(name, input_name, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // Data coping
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0) 
            putc(ch, out);
    
    // Clear
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error with closing files.\n");
    return 0;
}