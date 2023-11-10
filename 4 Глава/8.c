#include <stdio.h>
#define MILE 1.609
#define GALONE 3.785

int main(void) {
    float miles, galons;
    printf("Input number of miles: ");
    scanf("%f", &miles);
    printf("Input number of galons: ");
    scanf("%f", &galons);
    printf("Number of miles with 1 galon: %.1f\n", miles / galons);
    float km = miles * MILE, lt = galons * GALONE;
    printf("%f galons/100 miles\n", galons * 100 / miles);
    printf("%f litres/100 kilometres\n", lt * 100 / km);
    printf("%f miles/galon\n", miles / galons);
    printf("%f kilmetres/litre\n", km / lt);
    return 0;
}