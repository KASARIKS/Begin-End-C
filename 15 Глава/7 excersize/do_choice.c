#include "do_choice.h"
#include "output_menu.h"
#include "turn_flags.h"
#include "input_values.h"
struct info do_choice(char mode, struct info text_info, unsigned long *id) {
    switch (mode) {
    case 'a':
        *id = input_id();
        break;
    case 'b':
        text_info.size = input_size();
        break;
    case 'c':
        output_leveling_menu();
        text_info.leveling = input_leveling();
        break;
    case 'd':
        text_info.bolder = turn(text_info.bolder);
        break;
    case 'e':
        text_info.cursiv = turn(text_info.cursiv);
        break;
    case 'f':
        text_info.underlined = turn(text_info.underlined);
        break;
    default:
        break;
    }
    return text_info;
}