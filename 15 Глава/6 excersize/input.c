#include "input.h"
#include "output_menu.h"
#include <stdio.h>

char input_mode(struct info *text_info) {
    char mode;
    fflush(stdin);
    scanf("%c", &mode);
    while (mode < 'a' || mode > 'g') {
        printf("WRONG INPUT!\n");
        output_menu(text_info);
        fflush(stdin);
        scanf("%c", &mode);
    }
    return mode;
}

char input_leveling_mode(void) {
    char mode;
    fflush(stdin);
    scanf("%c", &mode);
    while (mode < 'a' || mode > 'c') {
        printf("WRONG INPUT!\n");
        output_leveling_menu();
        fflush(stdin);
        scanf("%c", &mode);
    }
    return mode;
}