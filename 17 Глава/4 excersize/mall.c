#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void) {
    Queue line, line_2;
    Item temp;
    double hours;
    int perhour;
    long cycle, cyclelimit;

    // First queue
    long turnaways = 0, customers = 0, served = 0;
    long sum_line = 0, line_wait = 0;

    // Second queue
    long turnaways_2 = 0, customers_2 = 0, served_2 = 0;
    long sum_line_2 = 0, line_wait_2 = 0;

    int wait_time = 0, wait_time_2 = 0;
    double min_per_cust;

    InitializeQueue(&line);
    InitializeQueue(&line_2);

    srand((unsigned int)time(0));
    puts("Study example: Zigmund Lander's consulation shop");
    puts("Input lenght of modelizing in hours:");
    scanf("%lf", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Input average number of clients, went for hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (QueueIsFull(&line) && QueueIsFull(&line_2)) turnaways++;
            else {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, QueueItemCount(&line) < QueueItemCount(&line_2) ? &line : &line_2);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line)) {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time_2 <= 0 && !QueueIsEmpty(&line_2)) {
            DeQueue(&temp, &line_2);
            wait_time_2 = temp.processtime;
            line_wait_2 += cycle - temp.arrive;
            served_2++;
        }
        if (wait_time > 0) wait_time--;
        if (wait_time_2 > 0) wait_time_2--;
        sum_line += QueueItemCount(&line);
        sum_line_2 += QueueItemCount(&line_2);
    } 

    if (customers > 0) {
        printf("joined clients: %ld\n", customers);
        printf("served clients: %ld\n", served+served_2);
        printf("average queue's length: %.2f\n", ((double)sum_line/cyclelimit+(double)sum_line_2/cyclelimit));
        printf("average time of waiting: %.2f mins\n", ((double)line_wait/served+(double)line_wait_2/served_2));
    } else {
        puts("There are no clients!");
    }

    EmptyTheQueue(&line);
    EmptyTheQueue(&line_2);
    puts("Program is ended.");

    return 0;
}

// Client information

bool newcustomer(double x) {
    return rand() * x / RAND_MAX < 1;
}

Item customertime(long when) {
    Item cust;
    
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}