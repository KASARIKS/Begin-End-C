#include <stdio.h>

int main(void) {
    int guess = 0, low = 0, high = 100;
    printf("Choose number in from 1 to 100. I'll try to guess ");
    printf("it. \nInput y, if my quessing is right and");
    printf("\n Input > if it's too big or < if too small.\n");
    guess += (high - low) / 2;
    printf("Your number is %d?\n", guess);
    printf("Input: ");
    char ch = getchar();
    while (1) {
        if (ch == '<') {
            low = guess;
            guess += (high - low) / 2;
        } else if (ch == '>') {
            high = guess;
            guess -= (high - low) / 2;
        } else if (ch == 'y') {
            break;
        } else {
            printf("Input y, > or <\n");
        }
        printf("Ok, then it's %d?\n", guess);
        printf("Input: ");
        fflush(stdin);
        ch = getchar();
    }
        
    printf("I know I'll do it!");
    return 0;
}