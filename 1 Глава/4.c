#include <stdio.h>

void jolly();
void deny();

int main(void) {
    jolly();
    jolly();
    jolly();
    deny();

    return 0;
}

void jolly() {
    printf("He's a jolly fellow\n");
}

void deny() {
    printf("Nobody can this deny");
}