#include <stdio.h>

int main(void) {
    printf("This program count results of counting by module.\n");
    printf("Input integer number that will work as the second operand: ");
    int second, first;
    scanf("%d", &second);
    printf("Now input first operand: ");
    scanf("%d", &first);
    while (first > 0) {
        printf("%d %% %d equil %d\n", first, second, first % second);
        printf("Input next number for first operand(<= 0 for exit from program): ");
        scanf("%d", &first);
    }
    printf("Done");
    return 0;
}