#include <stdio.h>
#include <string.h>
struct fullname {
    char fname[20];
    char lname[20];
};
struct bard {
    struct fullname name;
    int born, died;
};
struct bard willie;
struct bard *pt = &willie;

int main(void) {
    willie.born = 12;
    printf("willie.born = %d\n", willie.born);
    pt->born = 12;
    printf("pt->born = %d\n", pt->born);
    scanf("%d", &willie.born);
    printf("willie.born = %d\n", willie.born);
    scanf("%d", &pt->born);
    printf("pt->born = %d\n", pt->born);
    scanf("%s", willie.name.fname);
    printf("willie.name.fname = %s\n", willie.name.fname);
    scanf("%s", pt->name.lname);
    printf("pt->name.lname = %s\n", pt->name.lname);
    printf("Total name lenght: %d\n", strlen(pt->name.fname) + strlen(pt->name.lname));
    return 0;
}