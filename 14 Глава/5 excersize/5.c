#include "student.h"
#include <stdio.h>
#define CSIZE 4

void input(struct student *student) {
    printf("Input: ");
    while (scanf("%s %s %f %f %f", student->student_name.first_name, student->student_name.last_name, 
    &student->grade[0], &student->grade[1], &student->grade[2]) != 5) {
        printf("WRONG INPUT!\n");
        printf("Input: ");
        fflush(stdin);
    }
}

void average(struct student students[CSIZE]) {
    for (int i = 0; i < CSIZE; ++i) {
        students[i].average_grade = 0;
        for (int grade = 0; grade < 3; ++grade) students[i].average_grade += students[i].grade[grade];
        students[i].average_grade /= 3;
    }
}

void output(struct student studetns[CSIZE]) {
    for (int i = 0; i < CSIZE; ++i) 
        printf("%d. %s %s - %f %f %f - %f\n", i + 1,
            studetns[i].student_name.first_name, studetns[i].student_name.last_name,
            studetns[i].grade[0], studetns[i].grade[1], studetns[i].grade[2],
            studetns[i].average_grade);
}

int main(void) {
    struct student students[CSIZE] = {
        {{"Yaroslav", "Golovko"}},
        {{"Dasha", "Veshinina"}},
        {{"Roma", "Danilov"}},
        {{"Viyatkina", "Katiya"}}
    };
    for (int i = 0; i < CSIZE; ++i) {
        input(&students[i]);
    }
    average(students);
    output(students);

    return 0;
}