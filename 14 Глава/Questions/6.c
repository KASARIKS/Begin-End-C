#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct lens {
    float foclen;
    float fstop;
    char brand[30];
} LENS;

LENS **create_lens(int size, float *foclens, float *fstops, char brands[][30]) {
    LENS **lens_arr = (LENS **)malloc(sizeof(LENS*)*size);
    for (int i = 0; i < size; ++i) lens_arr[i] = (LENS*)malloc(sizeof(LENS));
    for (int i = 0; i < size; ++i) {
        lens_arr[i]->foclen = foclens[i];
        lens_arr[i]->fstop = fstops[i];
        strcpy(lens_arr[i]->brand, brands[i]);
    }
    return lens_arr;
}

void output_lens(LENS **lens_arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d. %s, %.0f %.1f\n", i + 1, lens_arr[i]->brand, lens_arr[i]->foclen, lens_arr[i]->fstop);
    }
}

int main(void) {
    int size = 5;
    float foclens[] = {100, 200, 300, 400, 500}, fstops[] = {5.0, 4.0, 3.0, 2.0, 1.0};
    char brands[][30] = {"Nicoon", "Sony", "Philips", "Nokia", "Nisaan"};
    LENS **lens_arr = create_lens(size, foclens, fstops, brands);
    output_lens(lens_arr, size);
    free(lens_arr);
    return 0;
}