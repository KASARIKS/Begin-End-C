#pragma once
struct info {
    unsigned int id: 8, size: 8;
    unsigned int leveling: 2;
    unsigned int bolder: 1, cursiv: 1, underlined: 1;
};

void constructor(struct info *text_info);