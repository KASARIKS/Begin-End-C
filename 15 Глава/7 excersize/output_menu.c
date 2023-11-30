#include "output_menu.h"
#include <stdio.h>

void output_menu(struct info *text_info, unsigned long id) {
    printf("ID  SIZE LEVELING    B      C      U\n");
    printf("%-3d %-3d    ", id, text_info->size);
    if (text_info->leveling == 0) printf("%6s", "left");
    else if (text_info->leveling == 1) printf("%6s", "middle");
    else if (text_info->leveling == 2) printf("%6s", "right");
    printf("    %-3s    %-3s    %-3s\n", 
    text_info->bolder == 0 ? "off" : "on", 
    text_info->cursiv == 0 ? "off" : "on", 
    text_info->underlined == 0 ? "off" : "on");
    printf("a) change id   b) change size   c) change leveling\n");
    printf("d) bolder      e) cursive       f) underlited\n");
    printf("g) exit\n");
}

void output_leveling_menu(void) {
    printf("Choose leveling: \n");
    printf("0) left        1) middle        2) right\n");
}