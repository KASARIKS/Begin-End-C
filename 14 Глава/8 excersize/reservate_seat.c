#include "reservate_seat.h"
#include <stdio.h>
#include <string.h>
int inputseatinfo(int *is_reservateds, char **first_names, char **second_names, int *ids) {
    char first_name[30], second_name[30];
    int id;

    // Input id
    while (1) {
        printf("Input id of seat(-1 for exit): ");
        while (scanf("%d", &id) != 1) {
            printf("WRONG INPUT!\n");
            printf("Input id of seat(-1 for exit): ");
            fflush(stdin);
        }
        if (id == -1) return 1;
        if (is_reservateds[id - 1]) printf("Seat %d is reservated!\n", id);
        else break;
    } 

    // Input pasanger name
    printf("Input first_name and last_name separated by space: ");
    scanf("%s %s", first_name, second_name);

    is_reservateds[id - 1] = 1;
    ids[id - 1] = id;
    strcpy(first_names[id - 1], first_name);
    strcpy(second_names[id - 1], second_name);

    return 0;
}

void reservateseat(int *is_reservateds, char **first_names, char **second_names, int *ids) {
    inputseatinfo(is_reservateds, first_names, second_names, ids);
}

int freeseat(int *is_reservateds, int size) {
    int id;

    // Input id
    while (1) {
        printf("Input id of seat(-1 for exit): ");
        while (scanf("%d", &id) != 1) {
            printf("WRONG INPUT!\n");
            printf("Input id of seat(-1 for exit): ");
            fflush(stdin);
        }
        if (id == -1) return 1;
        if (!is_reservateds[id - 1]) printf("Seat %d is free!\n", id);
        else if (id > size) printf("Seat %d doesn't exist!\n", id);
        else break;
    } 
    is_reservateds[id - 1] = 0;
    return 0;
}