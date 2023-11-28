#include <stdio.h>

void print_one(void) {printf("One, ");}
void print_two(void) {printf("two, ");}
void print_three(void) {printf("three, ");}
void light_crhistmas_tree(void) {printf("light Christmass tree!\n");}

int main(void) {
    void (*arr[4])(void) = {
        print_one,
        print_two,
        print_three,
        light_crhistmas_tree
    };
    for (int i = 0; i < 4; ++i) arr[i]();
    return 0;
}