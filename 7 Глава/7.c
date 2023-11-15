#include <stdio.h>
#define TOO_MUCH 1.5
#define ALL_$ 10
#define FIRST_300$ 0.15
#define SECOND_150$ 0.2
#define LAST_$ 0.25

int main(void) {
    int hours;
    printf("Input hours worked per week: ");
    scanf("%d", &hours);
    hours *= hours > 40 ? 1.5 : 1;
    int salary = ALL_$ * hours;
    printf("Salary withour taxes: %d$\n", salary);
    // Count taxes
    float tax = 0;
    for (int i = 0; i <= salary; ++i) {
        if (i < 300) tax += FIRST_300$;
        else if (i < 450) tax += SECOND_150$;
        else tax += LAST_$;
    }
    printf("Taxes: %f$\n", tax);
    printf("Usual salary: %f$", salary - tax);
    return 0;
}