#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void InitializeStack(Stack *stack) {
    stack->size = 0;
}

bool isEmpty(Stack *stack) {
    return stack->size == 0;
}

void Push(Stack *stack, int value) {
    Node *pnew = (Node*)malloc(sizeof(Node));
    pnew->value = value;
    if (isEmpty(stack)) {
        stack->top = pnew;
        stack->size++;
    }
    else {
        pnew->next = stack->top;
        stack->top = pnew;
        stack->size++;
    }
}

int Pop(Stack *stack) {
    if (!isEmpty(stack)) {
        int val = stack->top->value;
        stack->size--;
        stack->top = stack->top->next;
        return val;
    }
}