#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define SLEN 20

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int main(void) {
    Tree pets;
    char choice;
    
    InitializeTree(&pets); 
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a':
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d animals in the club \n", TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default:
                puts("Error in switch");
        }
    }

    DeleteAll(&pets);
    puts("Program is ended.");

    return 0;
}

char menu(void) {
    int ch;

    puts("Program membership in the club Nerfville Pet Club");
    puts("Input letter, near to your choice:");
    puts("a) add animal          l) output list of animals");
    puts("n) number of animals   f) animal search");
    puts("d) delete animal       q) quit");

    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n') continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL) puts("Input letter a, l, f, n, d or q:");
        else break;
    }

    if (ch == EOF) ch = 'q';

    return ch;
}

void addpet(Tree *pt) {
    Item temp;
    
    if (TreeIsFull(pt)) puts("There are no seats in the club!");
    else {
        puts("Input name of animal:");
        s_gets(temp.petname, SLEN);
        puts("Input type of animal:");
        s_gets(temp.petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree *pt) {
    if (TreeIsEmpty(pt)) puts("Notes doesn't exist!");
    else Traverse(pt, printitem);
}

void printitem(Item item) {
    printf("Animal: %-19s  Type: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt) {
    Item temp;

    if (TreeIsEmpty(pt)) {
        puts("Notes doesn't exist!");
        return;
    }

    puts("Input name of animal, you want to find:");
    s_gets(temp.petname, SLEN);
    puts("Input type of animal:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s by name %s ", temp.petkind, temp.petname);
    if (InTree(&temp, pt)) printf("Is in club.\n");
    else printf("Isn't in club.\n");
}

void droppet(Tree *pt) {
    Item temp;

    if (TreeIsEmpty(pt)) {
        puts("Notes doesn't exist!");
        return;
    }

    puts("Input name of animal, that need to kick out from club:");
    s_gets(temp.petname, SLEN);
    puts("Input type of animal:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s by name %s ", temp.petkind, temp.petname);

    if (DeleteItem(&temp, pt)) printf("Kicked out from club.\n");
    else printf("Isn't member of club.\n");
}

void uppercase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

char *s_gets(char *st, int n) {
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}