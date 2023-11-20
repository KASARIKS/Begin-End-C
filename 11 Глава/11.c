#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C 10
#define MAX_SIZE 1000

void output_menu(void);
int input_str(char str[MAX_SIZE]);
int input(char strs[C][MAX_SIZE]);
int inputchoice(void);
void original_output(char strs[C][MAX_SIZE]);
void ascii_output(char strs[C][MAX_SIZE]);
void upper_output(char strs[C][MAX_SIZE]);
void upper_word_output(char strs[C][MAX_SIZE]);
void makechoice(char strs[C][MAX_SIZE]);
void start(void);

int main(void) {
    start();
    return 0;
}

void start(void) {
    char strs[C][MAX_SIZE];
    int count_strs = input(strs);
    output_menu();
    makechoice(strs);
}

void output_menu(void) {
    printf("************************************************\n");
    printf("1. Output original list;\n");
    printf("2. Output with ASCII sequince;\n");
    printf("3. Output with upper length sequince;\n");
    printf("4. Output with upper length first word sequince;\n");
    printf("5. Exit;\n");
    printf("Chose one of options: ");
}

int input(char strs[C][MAX_SIZE]) {
    printf("Input 10 strings: ");
    int count_strs;
    for (count_strs = 0; count_strs < C; ++count_strs) {
        if (input_str(strs[count_strs]) == EOF) break;
    }
    return count_strs;
}

int input_str(char str[MAX_SIZE]) {
    char ch;
    int i = 0;
    for (i = 0; (ch = getchar()) != '\n'; ++i) {
        if (ch == EOF) break;
        str[i] = ch;
    };
    str[i] = '\0';
    fflush(stdin);

    return ch;
}

int inputchoice(void) {
    int choice;
    while(scanf("%d", &choice) != 1) {
        printf("WRONG INPUT!\n");
        output_menu();
    }
    return choice;
} 

void makechoice(char strs[C][MAX_SIZE]) {
    int choice = inputchoice();
    while (choice != 5) {
        switch (choice) {
        case 1:
            original_output(strs);
            break;
        
        case 2:
            ascii_output(strs);
            break;

        case 3:
            upper_output(strs);
            break;

        case 4:
            upper_word_output(strs);
            break;

        default:
            break;
        }
        output_menu();
        choice = inputchoice();
    }
}

void original_output(char strs[C][MAX_SIZE]) {
    printf("Original output: \n");
    for (int word = 0; word < C; ++word) {
        printf("%s\n", strs[word]);
    }
}

void ascii_output(char strs[C][MAX_SIZE]) {
    printf("Ascii output: \n");
    for (int i = 0; i < C; ++i) {
        printf("%s\n", strs[i]);
    }
}

int compare_len (const void * a, const void * b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);
    return (fa > fb) - (fa < fb);
}

void upper_output(char strs[C][MAX_SIZE]) {
    char strs_new[C][MAX_SIZE];
    for (int i = 0; i < C; ++i) {
        strcpy(strs_new[i], strs[i]);
    }
    printf("Upper output: \n");
    qsort(strs_new, C, MAX_SIZE, compare_len);
    for (int i = 0; i < C; ++i) {
        printf("%s\n", strs_new[i]);
    }
}

int first_word_len(const char *str) {
    int i = 0;
    for (; str[i] == ' '; ++i);
    for (; str[i] != ' '; ++i);
    return i;
}

int compare_len_f (const void * a, const void * b) {
    size_t fa = first_word_len((const char *)a);
    size_t fb = first_word_len((const char *)b);
    return (fa > fb) - (fa < fb);
}

void upper_word_output(char strs[C][MAX_SIZE]) {
    char strs_new[C][MAX_SIZE];
    for (int i = 0; i < C; ++i) {
        strcpy(strs_new[i], strs[i]);
    }
    printf("Upper word output: \n");
    qsort(strs_new, C, MAX_SIZE, compare_len_f);
    for (int i = 0; i < C; ++i) {
        printf("%s\n", strs_new[i]);
    }
}