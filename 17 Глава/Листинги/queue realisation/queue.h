#pragma once
#include <stdbool.h>

typedef int Item;
#define MAXQUEUE 10
typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int items;
} Queue;

// Queue initialization
// pq - pointer to queue
void InitializeQueue(Queue *pq);

// Check queue is full
// pq - pointer to queue
// return true if full, else in another case
bool QueueIsFull(const Queue *pq);

// Check queue is empty
// pq - pointer to queue
// return true if empty, else in another case
bool QueueIsEmpty(const Queue *pq);

// Return number of items in queue
// pq - pointer to queue
int QueueItemCount(const Queue *pq);

// Add element into end of queue
// Return True with success, False in another case
// pq - pointer to queue
bool EnQueue(Item item, Queue *pq);

// Delete element from end of queue
// Return True with success, False in another case
// pq - pointer to queue
bool DeQueue(Item *pitem, Queue *pq);

// Clear queue
// pq - pointer to queue
void EmptyTheQueue(Queue * pq);