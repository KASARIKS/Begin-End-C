#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct month {
    int id, number_days;
    char name[3];
};

struct month** create_months() {
    struct month **months = (struct month**)malloc(sizeof(struct month*)*12);
    for (int i = 0; i < 12; ++i) {
        months[i] = (struct month*)malloc(sizeof(struct month));
    }
    char names[12][4] = {"Jan\0", "Feb\0", "Mar\0", "Apr\0", "May\0", 
    "Jun\0", "Jul\0", "Aug\0", "Sep\0", "Oct\0", "Nov\0", "Dec\0"};
    int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; ++i) {
        months[i]->id = i + 1;
        strcpy(months[i]->name, names[i]);
        months[i]->number_days = days[i];
    }
    return months;
}

void output_months(struct month **months) {
    for (int i = 0; i < 12; ++i) {
        printf("%2d. %s: %d days.\n", months[i]->id, months[i]->name, months[i]->number_days);
    }
}

int count_days(struct month **months, int id) {
    int sum = 0;
    for (int i = 0; i < id; ++i) {
        sum += months[i]->number_days;
    }
    return sum;
}

int main(void) {
    struct month** months = create_months();
    output_months(months);
    printf("to Jul days: %d", count_days(months, 7));
    free(months);
    return 0;
}