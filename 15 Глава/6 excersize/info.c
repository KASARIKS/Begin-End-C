#include "info.h"

void constructor(struct info *text_info) {
    text_info->bolder = 0;
    text_info->cursiv = 0;
    text_info->underlined = 0;
    text_info->id = 1;
    text_info->leveling = 0;
    text_info->size = 12;
}