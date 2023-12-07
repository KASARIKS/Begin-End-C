#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist) {
    plist->end = NULL;
}

bool ListIsEmpty(const List *plist) {
    return plist->head->next == NULL;
}

// Странная хуйня, оно никогда не сработает \:0
bool ListIsFull(const List *plist) {
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    full = (pt == NULL);
    free(pt);

    return full;
}

unsigned int ListItemCount(const List *plist) {
    unsigned int count = 0;
    Node *pnode = plist->head->next;

    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

bool AddItem(Item item, List *plist) {
    Node *pnew;
    Node *scan = plist->head->next;

    pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL) return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) plist->head->next = pnew;
    else {
        while (scan->next != NULL) scan = scan->next;
        scan->next = pnew;
    }

    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)) {
    Node *pnode = plist->head->next;

    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist) {
    Node *psave;
    Node *node = plist->head;

    while (plist != NULL) {
        psave = node->next;
        free(node);
        node = psave;
    }
}

static void CopyToNode(Item item, Node *pnode) {
    pnode->item = item;
}