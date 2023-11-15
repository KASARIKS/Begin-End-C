#include <stdio.h>
#include <stdlib.h>

void input(int* numbers) {
    printf("Input 8 numbers: ");
    for (int i = 0; i < 8; ++i) {
        while (scanf("%d", &numbers[i]) != 1) {
            printf("This ins't number: ");
            fflush(stdin);
        }
    }
}

int main(void) {
    int* numbers = (int*)malloc(sizeof(int)*8);
    input(numbers);
    for (int i = 7; i >= 0; --i) {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}