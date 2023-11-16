#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void) {
    int choice;
    void count(void);
    while((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy cheap, sell expensive.\n");
                break;
            case 's':
                putchar('\a');
                break;
            case 'c':
                count();
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
    printf("Program finished.\n");
    return 0;
}

void count(void) {
    int n, i;
    printf("To what limit do you want counting? Input integer number:\n");
    n = get_int();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while (getchar() != '\n') 
        continue;
}

char get_choice(void) {
    int ch;
    printf("Input letter, corresponding the selected option:\n");
    printf("a. advice         s. sound\n");
    printf("c. count          e. exit\n");
    ch = get_first();
    while (ch != 'a' && ch != 's' && ch != 'c' && ch != 'e') {
        printf("Choice a, s, c or e.\n");
        ch = get_first();
    }
    return ch;
}

char get_first(void) {
    int ch;
    ch = getchar();
    while (ch == ' ') ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

int get_int(void) {
    int input;
    char ch;
    while (scanf("%d", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" not integer.\nInput ");
        printf("integer number, like 25, -1798 or 3: ");
    }
    return input;
}