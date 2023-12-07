#include <stdio.h>
#include <string.h>
#define MAX_FILMS 45
#define MAX_NAME 45

struct film {
    char name[MAX_NAME];
    int rate;
};

void output_movies(struct film *movies, int size) {
    printf("List of books: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d. %s, %d\\10.\n", i + 1, movies[i].name, movies[i].rate);
    }
}

int input(struct film *movies) {
    int i = 0;
    for (; i < MAX_FILMS; ++i) {
        printf("Input name and rating of film %d(0 0 for exit): ", i + 1);
        if (scanf("%s %d", movies[i].name, &movies[i].rate) != 2 || movies[i].name[0] == '0') break;
    }
    return i;
}

int main(void) {
    struct film movies[MAX_FILMS];
    int size = input(movies);
    output_movies(movies, size);
    printf("Program is ended.\n");
    return 0;
} 