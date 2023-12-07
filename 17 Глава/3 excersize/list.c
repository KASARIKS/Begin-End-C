#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist) {
    plist->items = 0;
}

bool ListIsEmpty(const List *plist) {
    return plist->items == 0;
}

// Not need
bool ListIsFull(const List *plist) {
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    full = (pt == NULL);
    free(pt);

    return full;
}

unsigned int ListItemCount(const List *plist) {
    return plist->items;
}

bool AddItem(Item item, List *plist) {
    plist->entries[plist->items++] = item;

    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)) {
    for (int i = 0; i < plist->items; ++i) {
        pfun(plist->entries[i]);
    }
}

// Not need, array is static allocated
void EmptyTheList(List *plist) {
    
}

// Not need
static void CopyToNode(Item item, Node *pnode) {
    pnode->item = item;
}