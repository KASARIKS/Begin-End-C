#include <stdio.h>
#include "starfolk.h"
struct bem deb = {
    6,
    {"Berbnazel", "Gwolkapwolk"},
    "Arcturan"
};
struct bem *pb = &deb;

void info(struct bem *pb) {
    printf("%s %s - this is %d-ended %s.\n", pb->title.first, pb->title.last, pb->limbs, pb->type);
}

int main(void) {
    info(pb);
    return 0;
}