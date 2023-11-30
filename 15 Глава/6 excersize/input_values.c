#include "input_values.h"
#include <stdio.h>
#include "output_menu.h"

unsigned int input_size(void) {
    unsigned int size;
    printf("Input size of text(0-127): ");
    while (scanf("%u", &size) != 1 || size < 0 || size > 127) {   
        printf("WRONG INPUT!\n");
        printf("Input size of text(0-127): ");
        fflush(stdin);
    }
    return size;
}
unsigned int input_id(void) {
    unsigned int id;
    printf("Input id of text(0-255): ");
    while (scanf("%u", &id) != 1 || id < 0 || id > 255) {   
        printf("WRONG INPUT!\n");
        printf("Input id of text(0-255): ");
        fflush(stdin);
    }
    return id;
}
unsigned int input_leveling(void) {
    unsigned int leveling;
    while (scanf("%u", &leveling) != 1 || leveling < 0 || leveling > 2) {   
        printf("WRONG INPUT!\n");
        output_leveling_menu();
        fflush(stdin);
    }
    return leveling;
}