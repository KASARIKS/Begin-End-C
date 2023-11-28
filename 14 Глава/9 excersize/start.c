#include "start.h"
#include "set_flight.h"
#include <stdio.h>
#include <string.h>
#define NUMSEATS 12
#define FILENAME1 "first_plane.txt"
#define FILENAME2 "second_plane.txt"
#define FILENAME3 "third_plane.txt"
#define FILENAME4 "fourth_plane.txt"
void fill_seats(struct seat seats[NUMSEATS], char *filename);
void save_seats(struct seat seats[NUMSEATS], char *filename);
void create_empty_planes(struct seat seats[NUMSEATS]);
void start(void) {
    // Create seats
    struct seat plane_1[NUMSEATS];
    struct seat plane_2[NUMSEATS];
    struct seat plane_3[NUMSEATS];
    struct seat plane_4[NUMSEATS];
    create_empty_planes(plane_1);
    create_empty_planes(plane_2);
    create_empty_planes(plane_3);
    create_empty_planes(plane_4);
    fill_seats(plane_1, FILENAME1);
    fill_seats(plane_2, FILENAME2);
    fill_seats(plane_3, FILENAME3);
    fill_seats(plane_4, FILENAME4);
    set_flight(plane_1, plane_2, plane_3, plane_4, NUMSEATS);
    save_seats(plane_1, FILENAME1);
    save_seats(plane_2, FILENAME2);
    save_seats(plane_3, FILENAME3);
    save_seats(plane_4, FILENAME4);
}

void fill_seats(struct seat seats[NUMSEATS], char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "rb")) != NULL) {
        for (int id = 0; id < NUMSEATS; ++id) {
            fscanf(fp, "%d %d %s %s", &seats[id].id, &seats[id].is_reservated, 
            seats[id].first_name, seats[id].second_name);
        }
    }
    fclose(fp);
}

void save_seats(struct seat seats[NUMSEATS], char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    for (int id = 0; id < NUMSEATS; ++id) {
        fprintf(fp, "%d %d %s %s\n", id + 1, seats[id].is_reservated, 
            seats[id].first_name, seats[id].second_name);
    }
    fclose(fp);
}

void create_empty_planes(struct seat seats[NUMSEATS]) {
    for (int id = 0; id < NUMSEATS; ++id) {
        seats[id].id = id, seats[id].is_reservated = 0;
        strcpy(seats[id].first_name, "empty"), strcpy(seats[id].second_name, "empty");
    }
}