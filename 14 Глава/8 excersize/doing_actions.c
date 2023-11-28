#include "doing_actions.h"
#include "output_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "show_info.h"
#include "reservate_seat.h"

void doing_actions(struct seat seats[], int size) {
    char ch;
    // Copies of structure
    int *ids = (int*)malloc(sizeof(int)*size), *is_reservateds = (int*)malloc(sizeof(int)*size);
    char **first_names = (char**)malloc(sizeof(char*)*size), **second_names = (char**)malloc(sizeof(char*)*size);
    for (int i = 0; i < size; ++i) {
        first_names[i] = (char*)malloc(sizeof(char)*size);
        second_names[i] = (char*)malloc(sizeof(char)*size);
        ids[i] = seats[i].id;
        is_reservateds[i] = seats[i].is_reservated;
        strcpy(first_names[i], seats[i].first_name);
        strcpy(second_names[i], seats[i].second_name);
    }

    while (ch != 'f') {
        output_menu();
        fflush(stdin);
        ch = getchar();
        switch (ch) {
            case 'a':
                printf("Free seats number: %d\n", getnumfreeseats(is_reservateds, size));
                break;
            
            case 'b':
                outlistfreeseats(is_reservateds, size);
                break;

            case 'c':
                outlistreservseats(is_reservateds, first_names, second_names, ids, size);
                break;

            case 'd':
                reservateseat(is_reservateds, first_names, second_names, ids);
                break;

            case 'e':
                freeseat(is_reservateds, size);
                break;
            
            case 'f':
                printf("Exit and saving data\n");
                for (int i = 0; i < size; ++i) {
                    seats[i].id = ids[i];
                    seats[i].is_reservated = is_reservateds[i];
                    strcpy(seats[i].first_name, first_names[i]);
                    strcpy(seats[i].second_name, second_names[i]);
                }
                return;
                break;
            
            default:
                printf("WRONG INPUT!\n");
                break;
        }
    }
    free(ids), free(is_reservateds);
    for (int i = 0; i < size; ++size) free(first_names[i]), free(second_names[i]);
    free(first_names), free(second_names);
}