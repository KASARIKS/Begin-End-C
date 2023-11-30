#include "start.h"
#include "output_menu.h"
#include "input.h"
#include "do_choice.h"
#include <stdio.h>
#include "info.h"

void start(void) {
    struct info text_info;
    constructor(&text_info);
    unsigned long id = 0;
    char mode;

    while (mode != 'g') {
        output_menu(&text_info, id);
        mode = input_mode(&text_info, id);
        text_info = do_choice(mode, text_info, &id);
    }
    printf("Program is ended.\n");
}