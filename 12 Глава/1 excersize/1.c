#include <stdio.h>
void critic(int *units);
int main(void) {
    int units;
    printf("How many pounds is weight?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You knew this!\n");
    return 0;
}

void critic(int *units) {
    printf("You are unlucky. Try again.\n");
    scanf("%d", units);
}