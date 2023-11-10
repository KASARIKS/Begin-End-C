#include <stdio.h>
#include <string.h>

int main(void) {
    char name[30];

    printf("Input name: ");
    scanf("%s", name);
    int len = strlen(name);
    
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("\"%*s\"", len + 3, name);
    return 0;
}