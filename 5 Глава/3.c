#include <stdio.h>
#define WEEK 7

int main(void) {
    int days_num;
    printf("Input number of days: ");
    scanf("%d", &days_num);
    while (days_num > 0) {
        printf("%d days is %d weeks and %d days\n", days_num, days_num / WEEK, days_num % WEEK);
        printf("Input number of days: ");
        scanf("%d", &days_num);
    }
}