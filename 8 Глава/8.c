#include <stdio.h>
void output_menu(void);
char get_first(void);
int input_choice(void);
float input_number(void);

int main(void) {
    int choice;
    output_menu();
    while ((choice = input_choice()) != 'e') {
        printf("Input first number: ");
        float a = input_number();
        printf("Input second number: ");
        float b = input_number();
        switch (choice) {
            case 'a':
                printf("%f + %f = %f\n", a, b, a + b);
                break;
            case 'b':
                printf("%f + %f = %f\n", a, b, a - b);
                break;
            case 'c':
                printf("%f * %f = %f\n", a, b, a * b);
                break;
            case 'd':
                while (b == 0) {
                    printf("Input second number other then zero: ");
                    b = input_number();
                }
                printf("%f / %f = %f\n", a, b, a / b);
                break;
            case 'e':
                printf("Program ended.");
                break;
            default:
                printf("Error! The author of programm don't know what hapened.\n");
                printf("Kisk his ass really strong.\n");
                break;
        }
        output_menu();
    }
    return 0;
}

void output_menu(void) {
    printf("Choice operation you want: \n");
    printf("a. addition     b. substriction\n");
    printf("c. multiplication   d. division\n");
    printf("e. ending\n");
}

int input_choice(void) {
    fflush(stdin);
    int ch;
    ch = get_first();
    while (ch < 'a' || ch > 'e') {
        printf("WRONG INPUT!\n");
        output_menu();
        ch = get_first();
    }
    return ch;
}

// Input string and return first symbol
char get_first(void) {
    int ch;
    ch = getchar();
    while (ch == ' ') ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

float input_number(void) {
    float number;
    while (scanf("%f", &number) != 1) {
        printf("This isn't a number: ");
        fflush(stdin);
    }
    return number;
}