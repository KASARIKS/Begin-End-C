#pragma once
#include <stdbool.h>

#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node {
    Item item;
    struct node *next;
} Node;
typedef Node *List;

// Initializing list
// plist - pointer to list
void InitializeList(List *plist);

// Is list empty
// plist - pointer to list
// Return True if list empty and False in different case
bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

// Return count of list's items
// plist - pointer to list
unsigned int ListItemCount(const List *plist);

// Add item to list if possible
// return True with success, else False
bool AddItem(Item item, List *plist);

// Do function with list
// *plist - pointer to list
// *pfun - function
void Traverse(const List *plist, void (*pfun)(Item item));

// Clear list
// plist - pointer to list
void EmptyTheList(List *plist);