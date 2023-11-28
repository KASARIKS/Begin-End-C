#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char *s_gets(char *st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void delete(struct book library[MAXBKS], int id);

int main(void) {
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open file book.dat\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0)
            puts("Current content of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS) {
        fputs("File book.dat is filled.", stderr);
        exit(2);
    }
    puts("Input names of new books.");
    puts("Press [enter] at the end of string for ending input.");
    puts("\"delete\" for deleting book.");
    puts("\"modify\" for modifing book.");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        // delete
        if (!strcmp("delete", library[count].title)) {
            delete(library, count);
            continue;
        }
        if (!strcmp("modify", library[count].title)) {
            delete(library, count);
            continue;
        }
    
        puts("Now input author's name.");
        s_gets(library[count].author, MAXAUTL);

        puts("Now input price of book.");
        scanf("%f", &library[count].value);
        ++count;
        while (getchar() != '\n') continue;
        if (count < MAXBKS) puts("Input name of the next book.");
    }
    fclose(pbooks);
    if ((pbooks = fopen("book.dat", "w+b")) == NULL) {
        fputs("Can't open file book.dat\n", stderr);
        exit(1);
    }

    if (count > 0) {
        puts("Catalog of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        fwrite(&library, size, count, pbooks);
    } else puts("No books at all? Really bed.\n");
    puts("Program is ended.\n");
    fclose(pbooks);    
    return 0;
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

void delete(struct book library[MAXBKS], int id) {
    printf("Input id of book: "); 
    scanf("%d", &id);
    printf("Book deleted.\n");
    fflush(stdin);
    puts("Input name of the next book.");
    s_gets(library[id].title, MAXTITL);
    puts("Now input author's name.");
    s_gets(library[id].author, MAXAUTL);
    puts("Now input price of book.");
    scanf("%f", &library[id].value);
}