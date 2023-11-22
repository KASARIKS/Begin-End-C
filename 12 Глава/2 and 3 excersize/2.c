// second and third excersizes
#include <stdio.h>
#include "pe12-a.h"

int main(void) {
    auto int mode;
    auto double trip, fuel;
    printf("Input 0 for metrci mode or 1 for american mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        set_mode(&mode);
        get_info(&trip, &fuel);
        show_info(mode, trip, fuel);
        printf("Input 0 for metrci mode or 1 for american mode(-1 for ending): ");
        scanf("%d", &mode);
    }
    printf("Program ended.\n");
    return 0;
}