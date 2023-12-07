#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 45

struct film {
    char title[MAX_NAME];
    int rating;
    struct film *next;
};

void free_list(struct film *head, struct film *current) {
    current = head;
    while (current != NULL) {
        current = head;
        head = current->next;
        free(current);
    }
}

void output_list(struct film *head, struct film *current) {
    current = head;
    printf("List of films: \n");
    while (current != NULL) {
        printf("%s %d\n", current->title, current->rating);
        current = current->next;
    }
}

void input_list(struct film **head, struct film **current, struct film **prev) {
    *current = (struct film*)malloc(sizeof(struct film));
    while (scanf("%s %d", (*current)->title, &((*current)->rating)) != 2 || (*current)->title[0] != '0') {
        if (*head == NULL) *head = *current;
        else (*prev)->next = *current;
        (*current)->next = NULL;
        *prev = *current;
        printf("Input film(0 0 for exit): ");
        *current = (struct film*)malloc(sizeof(struct film));
    }
}

int main(void) {
    struct film *head = NULL;
    struct film *prev, *current;
    printf("Input film(0 0 for exit): ");
    input_list(&head, &current, &prev);
    output_list(head, current);
    free_list(head, current);
}