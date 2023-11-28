#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *s_gets(char *st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int comp_titles (const struct book *i, const struct book *j) {return i->title[0] - j->title[0];}
int comp_prices (const struct book *i, const struct book *j) {return i->value - j->value;}

int main(void) {
    struct book library[MAXBKS];
    int count = 0;
    int index;
    
    printf("Input the name of book.\n");
    printf("Press [enter] in the begin of string for ending input.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        printf("Now input author's name data.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now input price.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n') continue;
        if (count < MAXBKS) printf("Input name of the next book.\n");
    }
    if (count > 0) {
        printf("Catalog of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        qsort(library, count, sizeof(struct book), (int(*) (const void *, const void *)) comp_titles);
        printf("\n");
        printf("Sorted by title:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        qsort(library, count, sizeof(struct book), (int(*) (const void *, const void *)) comp_prices);
        printf("\n");
        printf("Sorted by price:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    } else printf("No books at all? Really bad.\n");

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) *find = '\0';
        else
            while (getchar() != '\n') continue;
    }
    return ret_val;
}