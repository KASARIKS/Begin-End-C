#include <stdio.h>
#include <stdlib.h>
int *make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void) {
    int *pa;
    int size;
    int value;
    printf ("Input number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0) {
        printf("Input value for initialization: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Input number of elemnts (<1 for ending): ");
    }
    printf("Programm is ended.\n");
    return 0;
}

int *make_array(int elem, int val) {
    int * arr = (int *)malloc(sizeof(int)*elem);
    for (int i = 0; i < elem; ++i) arr[i] = val;
    return arr;
}

void show_array(const int ar[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ar[i], i);
        if ((i + 1) % 8 == 0) printf("\n");
    }
    printf("\n");
}