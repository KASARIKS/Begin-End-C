#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    printf("Input data with # at the end: ");
    char ch;
    int sp = 0, en = 0, an = 0;
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case ' ':
                ++sp;
                break;
            case '\n':
                ++sp;
                break;
            
            default:
                ++an;
                break;
        }
    }
    int len;
    if (an > sp || an > en) len = floor(log10(abs(an))) + 1;
    else if (sp > en) len = floor(log10(abs(sp))) + 1; 
    else len = floor(log10(abs(en))) + 1;

    printf("Spaces:  %*d\n", len, sp);
    printf("Enters:  %*d\n", len, en);
    printf("Another: %*d\n", len, an);
    return 0;
}