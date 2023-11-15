#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TOO_MUCH 1.5
#define FIRST_300$ 0.15
#define SECOND_150$ 0.2
#define LAST_$ 0.25
void menu_output();
void menu_input(int *choice);
void hours_input(int *hours);
float count_tax(int salary);
void print_wall(int len);
void result_output(int salary, float tax);

int main(void) {
    const float menu_bits[] = {8.75, 9.23, 10.00, 11.20};
    int choice;

    menu_output();
    menu_input(&choice);

    while (choice != 5) {
        int hours;
        hours_input(&hours);
        int salary = menu_bits[choice - 1] * hours;
        float tax = count_tax(salary);
        result_output(salary, tax);
        menu_output();
        menu_input(&choice);
    }
    return 0;
}

void menu_output() {
    printf("******************************************************\n");
    printf("Input appropriate number bid what you want or action: \n");
    printf("1) $8.75/h                   2) $9.23/h\n");
    printf("3) $10.00/h                  4) $11.20/h\n");
    printf("5) Exit\n");
    printf("******************************************************\n");
}

void menu_input(int *choice) {
    while (scanf("%d", choice) != 1 || *choice > 5 || *choice < 1) {
        printf("Wrong input!\n");
        menu_output();
        fflush(stdin);
    }
}

void hours_input(int *hours) {
    printf("Input hours worked per week: ");
    while (scanf("%d", hours) != 1) {
        printf("Input integer number: ");
        fflush(stdin);
    }
    *hours *= *hours > 40 ? 1.5 : 1;
}

float count_tax(int salary) {
    float tax = 0;
    for (int i = 0; i <= salary; ++i) {
        if (i < 300) tax += FIRST_300$;
        else if (i < 450) tax += SECOND_150$;
        else tax += LAST_$;
    }
    return tax;
}

void result_output(int salary, float tax) {
    int len = floor(log10(abs(salary))) + 1;
    len += 3;

    print_wall(len);
    printf("| Salary withour taxes | %*d$ |\n", len, salary);
    printf("| Taxes                | %*.2f$ |\n", len, tax);
    printf("| Usual salary         | %*.2f$ |\n", len, salary - tax);
    print_wall(len);
}

void print_wall(int len) {
    printf("+----------------------+-");
    for (int i = 0; i < len; ++i) printf("-");
    printf("--+\n"); 
}