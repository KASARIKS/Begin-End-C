#include <stdio.h>
#include <string.h>
#include "month_name.h"

struct date
{
    int day, year;
    char month[15];
};


int main(void) {
    struct date first_date; 
    printf("Input Day, month, year separated by space: ");
    while (scanf("%d %s %d", &first_date.day, &first_date.month, &first_date.year) != 3) {
        printf("WRONG INPUT!\n");
        printf("Input Day, month, year separated by space: ");
        fflush(stdin);
    }

    int month_id;
    if (strlen(first_date.month) == 1) month_id = first_date.month[0] - 49;
    else {
        for (month_id = 0; !strstr(names.full_name[month_id], first_date.month); ++month_id);
    }

    int sum_days = month_id > 1 && first_date.year % 4 == 0 ? 1 : 0;
    for (int tmp_id = 0; tmp_id < month_id; ++tmp_id) sum_days += names.days[tmp_id];
    sum_days += first_date.day - 1;
    printf("From January 1 %d to %s %d %d is %d days.\n", first_date.year, names.full_name[month_id], first_date.day, first_date.year, sum_days);
    
    return 0;
}