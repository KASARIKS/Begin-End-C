#include "confirmate.h"
#include <stdio.h>
#include <string.h>
void confirmate(int *is_reservateds, char **first_names, char **second_names) {
    int id;
    input_seat(is_reservateds, &id);
    if (id == -1) {
        is_reservateds[id] = 0;
        strcpy(first_names[id], "empty");
        strcpy(second_names[id], "empty");
    } else {
        printf("Seat %d is reservated by %s %s and confirmated!\n", id, first_names, second_names);
    }
}

void input_seat(int *is_reservateds, int *id) {
    while (1) {
        printf("Input id of seat(-1 for exit): ");
        while (scanf("%d", id) != 1) {
            printf("WRONG INPUT!\n");
            printf("Input id of seat(-1 for exit): ");
            fflush(stdin);
        }
        if (!is_reservateds[*id - 1]) printf("Seat %d isnt reservated!\n", *id);
        else break;
    }
}