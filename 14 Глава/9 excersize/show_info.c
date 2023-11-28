#include "show_info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getnumfreeseats(int *seats, int size) {
    int count_free = 0;
    for (int id = 0; id < size; ++id) {
        if (!seats[id]) {
            ++count_free;
        }
    }

    return count_free;
}

void outlistfreeseats(int *seats, int size) {
    printf("Free seats: \n");
    for (int i = 0; i < size; ++i)
        if (!seats[i]) 
            printf("Seat %d\n", i + 1);
}

struct seat_tmp {
    int is_reservated, id;
    char first_name[30], second_name[30];
};

int cmp_seats(const struct seat_tmp *s1, const struct seat_tmp *s2) {
    return s1->first_name[0] - s2->first_name[0];
}

void outlistreservseats(int *is_reservateds, char **first_names, char **second_names, int *ids, int size) {
    printf("Reservated seats: \n");
    struct seat_tmp *seats = (struct seat_tmp*)malloc(sizeof(struct seat_tmp)*size);
    for (int i = 0; i < size; ++i) {
        strcpy(seats[i].first_name, first_names[i]);
        strcpy(seats[i].second_name, second_names[i]);
        seats[i].is_reservated = is_reservateds[i];
        seats[i].id = ids[i];
    }
    qsort(seats, size, sizeof(struct seat_tmp), (int(*)(const void *, const void *))cmp_seats);
    int count_reserv = 0;
    for (int i = 0; i < size; ++i) 
        if (seats[i].is_reservated) {
            printf("Seat %d - %s %s\n", seats[i].id, seats[i].first_name, seats[i].second_name);
            ++count_reserv;
        }
    if (!count_reserv) printf("No reservated seats!\n");
    free(seats);
}