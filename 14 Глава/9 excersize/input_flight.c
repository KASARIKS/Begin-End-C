#include "input_flight.h"
#include <stdio.h>
#include "output_flight_menu.h"

void input_flight(char *ch) {
    scanf("%c", ch);
    while (*ch < '1' && *ch > '5') {
        printf("WRONG INPUT!\n");
        outputflightmenu();
        fflush(stdin);
        scanf("%c", ch);
    }
}