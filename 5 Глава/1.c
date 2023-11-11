#include <stdio.h>
#define HOUR 60

int main(void) {
    int minutes;
    printf("Input number of minutes(0 or smaller for exit): ");
    scanf("%d", &minutes);
    while (minutes > 0) {
        printf("%d hours and %d minutes\n", minutes / HOUR, minutes % HOUR);
        printf("Input number of minutes(0 or smaller for exit): ");
        scanf("%d", &minutes);
    }
    return 0;
}