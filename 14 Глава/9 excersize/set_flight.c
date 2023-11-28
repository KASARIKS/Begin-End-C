#include "set_flight.h"
#include "output_flight_menu.h"
#include "input_flight.h"
#include <stdio.h>

// 102 and 311 flights are first and second plane
// 444 and 519 flights are third and fourth plane
// first and second are same plane and third and fourth are same plane
// There are different flights
void set_flight(struct seat plane_1[], struct seat plane_2[], 
struct seat plane_3[], struct seat plane_4[], int size) {
    char ch;
    while (ch != 'f') {
        fflush(stdin);
        outputflightmenu();
        input_flight(&ch);
        switch (ch) {
        case 'a':
            printf("Flight 102, plane 1: \n");
            doing_actions(plane_1, size);
            break;
        case 'b':
            printf("Flight 311, plane 1: \n");
            doing_actions(plane_2, size);
            break;
        case 'c':
            printf("Flight 444, plane 2: \n");
            doing_actions(plane_3, size);
            break;
        case 'd':
            printf("Flight 519, plane 2: \n");
            doing_actions(plane_4, size);
            break;
        case 'f':
            printf("Exit and saving.\n");
            break;
        default:
            break;
        }
    }
}