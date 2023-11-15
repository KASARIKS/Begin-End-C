#include <stdio.h>

int main(void) {
    char let;
    printf("Input letter of English alphabet: ");
    scanf("%c", &let);
    for (char i = 'A'; i <= let; ++i) {
        for (int j = i; j < let; ++j) 
            printf(" ");

        for (int j = 'A'; j != i; ++j) 
            printf("%c", j);
        
        for (int j = i; j >= 'A'; --j)
            printf("%c", j);

        printf("\n");
        
    }
    return 0;
}