#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void showmovies(Item item);
char *s_gets(char *st, int n);
int main(void) {
    List movies;
    Item temp;

    InitializeList(&movies);
    if (ListIsFull(&movies)) {
        fprintf(stderr, "Memory doesn't exist! Program is ended.\n");
        exit(1);
    }

    // Keeping data
    puts("Input name of first film: ");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Input your value of rating <0-10>: ");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') continue;
        if (AddItem(temp, &movies) == false) {
            fprintf(stderr, "Problem with memory allocation\n");
            break;
        }

        if (ListIsFull(&movies)) {
            puts("List is full.");
            break;
        }
        puts("Input name of next film (or empty string for ending input): ");
    }

    // Output
    if (ListIsEmpty(&movies)) printf("Data wasn't input");
    else {
        printf("List of films: \n");
        Traverse(&movies, showmovies);
    }
    printf("You have been input %d films.\n", ListItemCount(&movies));

    // Clear
    EmptyTheList(&movies);
}

void showmovies(Item item) {
    printf("Film: %s Rating: %d\n", item.title, item.rating);
}

char *s_gets(char *st, int n) {
    char *ret_val, *find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}