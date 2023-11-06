#include <stdio.h>

int main(void) {
    double mol = 3.0 * 10e-23;
    double kvart = 950;
    double qvarts_number;
    printf("Input number of qvarts: ");
    scanf("%lf", &qvarts_number);
    printf("Number of molekuls: %.0lf", qvarts_number * kvart / mol);
}