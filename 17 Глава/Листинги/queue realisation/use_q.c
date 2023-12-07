#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue line;
    Item temp;
    char ch;

    InitializeQueue(&line);
    puts("Testing queue's interface. Input a, for adding value");
    puts("input d, for deleting value, or input q for exit from program.");
    while ((ch = getchar()) != 'q') {
        if (ch != 'a' && ch != 'd') continue;
        if (ch == 'a') {
            printf("Integer number for adding: ");
            scanf("%d", &temp);
            if (!QueueIsFull(&line)) {
                printf("Adding %d into queue\n", temp);
                EnQueue(temp, &line);
            } else puts("Queue is filled!");
        } else {
            if (QueueIsEmpty(&line)) puts("Elements for deleting doesn't exist!");
            else {
                DeQueue(&temp, &line);
                printf("Deleting %d from queue\n", temp); 
            }
        }
        printf("%d element(s) int queue\n", QueueItemCount(&line));
        puts("Input a for adding, d for deleting, or q for exit from program: ");
    }

    EmptyTheQueue(&line);
    puts("Program is ended.");
}