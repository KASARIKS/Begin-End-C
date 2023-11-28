#include "start.h"
#include "doing_actions.h"
#include <stdio.h>
#define NUMSEATS 12
#define FILENAME "first_plane.txt"
void fill_seats(struct seat seats[NUMSEATS]);
void save_seats(struct seat seats[NUMSEATS]);
void start(void) {
    // Create seats
    struct seat seats[NUMSEATS];
    for (int id = 0; id < NUMSEATS; ++id) seats[id].id = id, seats[id].is_reservated = 0;
    fill_seats(seats);
    doing_actions(seats, NUMSEATS);
    save_seats(seats);
}

void fill_seats(struct seat seats[NUMSEATS]) {
    FILE *fp;
    if ((fp = fopen(FILENAME, "rb")) != NULL) {
        for (int id = 0; id < NUMSEATS; ++id) {
            fscanf(fp, "%d %d %s %s", &seats[id].id, &seats[id].is_reservated, 
            seats[id].first_name, seats[id].second_name);
        }
    }
    fclose(fp);
}

void save_seats(struct seat seats[NUMSEATS]) {
    FILE *fp;
    fp = fopen(FILENAME, "wb");
    for (int id = 0; id < NUMSEATS; ++id) {
        fprintf(fp, "%d %d %s %s\n", id + 1, seats[id].is_reservated, 
            seats[id].first_name, seats[id].second_name);
    }
    fclose(fp);
}