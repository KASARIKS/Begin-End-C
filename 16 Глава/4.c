#include <time.h>
#include <stdio.h>

void wait(double seconds) {
    clock_t first = clock();
    while (((double)(clock() - first) / CLOCKS_PER_SEC) < seconds);
}

int main(void) {
    double seconds = 5.5;
    printf("Wait for %f seconds...\n", seconds);
    wait(seconds);
    printf("Done!\n");
    return 0;
}