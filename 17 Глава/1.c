#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 45

struct film {
    char title[MAX_NAME];
    int rating;
    struct film *next; 
    struct film *last;
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
        //printf("%s %d\n", current->last->title, current->last->rating);
        printf("%s %d\n", current->title, current->rating);
        current = current->next;
    }
}

void output_list_reverse(struct film *last_el, struct film *last_h) {
    last_el = last_h;
    printf("Reversed list of films: \n");
    while (last_el != NULL) {
        //printf("a a\n");
        printf("%s %d\n", last_el->title, last_el->rating);
        last_el = last_el->last;
    }
}

void input_list(struct film **head, struct film **current, struct film **prev, struct film **last) {
    *current = (struct film*)malloc(sizeof(struct film));
    while (scanf("%s %d", (*current)->title, &((*current)->rating)) != 2 || (*current)->title[0] != '0') {
        if (*head == NULL) {
            *prev = NULL;
            *head = *current;
            (*current)->last = *prev;
        }
        else {
            (*prev)->next = *current;
            (*current)->last = *prev;
        }
        (*current)->next = NULL;
        *prev = *current;
        printf("Input film(0 0 for exit): ");
        *current = (struct film*)malloc(sizeof(struct film));
    }
    *last = (*prev);
    //printf("%s %d\n", (*last)->title, (*last)->rating);
}

int main(void) {
    struct film *head = NULL, *last = NULL;
    struct film *prev, *current;
    printf("Input film(0 0 for exit): ");
    input_list(&head, &current, &prev, &last);
    output_list(head, current);
    output_list_reverse(current, last);
    free_list(head, current);
}