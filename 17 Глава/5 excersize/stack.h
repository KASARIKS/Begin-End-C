#pragma once
#include <stdbool.h>

typedef int Value;
typedef struct node {
    Value value;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    int size;
} Stack;

// Rear = null, count = 0
void InitializeStack(Stack *stack); 

bool isEmpty(Stack *stack);

void Push(Stack *stack, int value);

int Pop(Stack *stack);