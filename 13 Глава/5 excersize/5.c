#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000
int main() {
    double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    for (i = 0; i < ARSIZE; i++) 
        numbers[i] = 100.0 * i + 1.0 / (i + 1);

    if ((iofile = fopen(file, "wb")) == NULL) {
        fprintf(stderr, "Can't open the file %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL) {
        fprintf(stderr, "Can't open the file %s for some access.\n", file);
        exit(EXIT_FAILURE);
    }

    printf("Input index in interval 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
        pos = (long) i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("There is value %f for this index.\n", value);
        printf("Input next index(or out of limits for exit):\n");
    }
    fclose(iofile);
    puts("Program is ended.");
    return 0;
} 