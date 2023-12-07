#pragma once
typedef struct item {
    int num;
} Item;

typedef struct node {
    Item value;
    Node *next;
} Node;  
typedef Node *Stack;

bool AddItem(Item item, Stack stack);