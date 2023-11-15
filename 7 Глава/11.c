#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 0 - arti, 1 - sve, 2 - car
const float VEGS[] = {2.05, 1.15, 1.09};
// 0 - <= 5, 1 - 5 < x <= 20
const float SEND[] = {6.50, 14.00};
#define MUCH 0.50

void menu_output();
void add_weight(float weight, float *food);
int input_weight(const char *food_name);
void input(float *arti, float *sve, float *car);
void count(float all[], float price_one_type[], float *sum_veg, float *price_send, float *price_all);
int field_length(float price_one_type, char *names);
void print_wall(int lengths[], int size);
void print_wall_simple(int lengths[], int size);
void output_total_price(int lengths[], int size, float price_all, float price_send);
void output_price(int lengths[], int size, float all[], float price_one_type[]);
void output(float all[], float price_one_type[], float sum_veg, float price_send, float price_all);

int main(void) {
    float arti = 0, sve = 0, car = 0;
    float all[] = {arti, sve, car};
    input(&all[0], &all[1], &all[2]);
    // Output data
    float price_one[] = {VEGS[0], VEGS[1], VEGS[2]}, price_one_type[] = {0, 0, 0};
    float sum_veg, price_send, price_all;
    count(all, price_one_type, &sum_veg, &price_send, &price_all);
    output(all, price_one_type, sum_veg, price_send, price_all);
    return 0;
}

void input(float *arti, float *sve, float *car) {
    char choice;
    int flag = 1;
    float weight;
    while (flag) {
        fflush(stdin);
        menu_output();
        scanf("%c", &choice);
        switch (choice) {
            case 'a':
                weight = input_weight("artishoks");
                add_weight(weight, arti);
                break;
            case 'b':
                weight = input_weight("svekla");
                add_weight(weight, sve);
                break;
            case 'c':
                weight = input_weight("carrot");
                add_weight(weight, car);
                break;
            case 'q':
                printf("ORDER SENDED!\n");
                flag = 0;
                break;
            default:
                printf("WRONG INPUT!\n");
                break;
        }
    }
}

void menu_output() {
    printf("****************************\n");
    printf("Input letter of action: \n");
    printf("a) Input weight of artishoks\n");
    printf("b) Input weight of svekla\n");
    printf("c) Input weight of carrot\n");
    printf("q) Exit\n");
    printf("****************************\n");
}

void add_weight(float weight, float *food) {
    *food += weight;
}

int input_weight(const char *food_name) {
    float weight;
    printf("Input weight of %s: ", food_name);
    while (scanf("%f", &weight) != 1) {
        printf("Input integer number: ");
        fflush(stdin);
    }
    return weight;
}

void count(float all[], float price_one_type[], float *sum_veg, float *price_send, float *price_all) {
    *sum_veg = 0, *price_all = 0;
    for (int i = 0; i < 3; ++i) {
        price_one_type[i] = all[i] * VEGS[i];
        if (price_one_type[i] > 100) price_one_type[i] *= 0.95;
        *price_all += price_one_type[i];
        *sum_veg += all[i];
    }
    if (*sum_veg <= 5) 
        *price_send = SEND[0] * *sum_veg;
    else if (*sum_veg > 5 && *sum_veg <= 20)
        *price_send = SEND[1] * *sum_veg;
    else {
        *price_send = SEND[1] * 20;
        *price_send += (*sum_veg - 20) * MUCH;
    }
}

void output(float all[], float price_one_type[], float sum_veg, float price_send, float price_all) {
    int lengths[] = {
        field_length(price_one_type[0], "Artishok"),
        field_length(price_one_type[1], "Svekla"),
        field_length(price_one_type[2], "Carrot")
    };
    
    output_price(lengths, 3, all, price_one_type);
    printf("\n");
    output_total_price(lengths, 3, price_all, price_send);    
}

int field_length(float price_one_type, char *names) {
    return floor(log10(abs(price_one_type))) + 4 > strlen(names) ? floor(log10(abs(price_one_type))) + 4 : strlen(names);
}

void print_wall(int lengths[], int size) {
    printf("+--------------+");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < lengths[i]; ++j) printf("-");
        printf("---+");
    }
    printf("\n");
}

void print_wall_simple(int lengths[], int size) {
    printf("+--------------+");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < lengths[i]; ++j) printf("-");
        printf("---");
    }
    for (int i = 0; i < size - 1; ++i) printf("-");
    printf("+\n");
}

void output_total_price(int lengths[], int size, float price_all, float price_send) {
    print_wall_simple(lengths, size);
    printf("| Price        | %-*.2f          |\n", lengths[0] + lengths[1] + lengths[2], price_all);
    print_wall_simple(lengths, size);
    printf("| Sale         | %-*.2f          |\n", lengths[0] + lengths[1] + lengths[2], price_all > 100 ? 0.05 : 0);
    print_wall_simple(lengths, size);
    printf("| Price send   | %-*.2f          |\n", lengths[0] + lengths[1] + lengths[2], price_send);
    print_wall_simple(lengths, size);
    printf("| Price + send | %-*.2f          |\n", lengths[0] + lengths[1] + lengths[2], price_all + price_send);
    print_wall_simple(lengths, size);
}

void output_price(int lengths[], int size, float all[], float price_one_type[]) {
    print_wall(lengths, size);
    printf("|              |  %*s |  %*s |  %*s |\n", lengths[0], "Artishok", lengths[1], "Svekla", lengths[2], "Carrot");
    print_wall(lengths, size);
    printf("| One price    | %*.2f$ | %*.2f$ | %*.2f$ |\n", lengths[0], VEGS[0], lengths[1], VEGS[1], lengths[2], VEGS[2]);
    print_wall(lengths, size);
    printf("| Weight       | %*.2f$ | %*.2f$ | %*.2f$ |\n", lengths[0], all[0], lengths[1], all[1], lengths[2], all[2]);
    print_wall(lengths, size);
    printf("| All price    | %*.2f$ | %*.2f$ | %*.2f$ |\n", lengths[0], price_one_type[0], lengths[1], price_one_type[1], lengths[2], price_one_type[2]);
    print_wall(lengths, size);
}