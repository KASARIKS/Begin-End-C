#include <stdio.h>
double sum(double a, double b) {return a + b;}
double deg(double a, double b) {return a - b;}
double mul(double a, double b) {return a * b;}
double seq(double a, double b) {return a / b;}

int main(void) {
    double(*foos[])(double a, double b) = {sum, deg, mul, seq};
    
    return 0;
}