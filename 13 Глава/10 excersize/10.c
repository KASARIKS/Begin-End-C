#include <stdio.h>

FILE *open_file()
{
    char file_name[80];
    printf("Input file_name: ");
    scanf("%s", file_name);
    FILE *fp;
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        return NULL;
    }
    return fp;
}

void output(FILE *fp, int pos)
{
    fseek(fp, pos, SEEK_SET);
    char ch;
    fread(&ch, sizeof(char), 1, fp);
    putchar(ch);
    while (ch != '\n')
    {
        fread(&ch, sizeof(char), 1, fp);
        putchar(ch);
    }
    fread(&ch, sizeof(char), 1, fp);
    putchar(ch);
    while (ch != '\n')
    {
        fread(&ch, sizeof(char), 1, fp);
        putchar(ch);
    }
}

int main(void)
{
    FILE *fp;
    if ((fp = open_file()) == NULL)
    {
        printf("File doesn't exists!\n");
    }
    else
    {
        int pos;
        printf("Input position: ");
        while (scanf("%d", &pos) == 1 && pos >= 0)
        {
            output(fp, pos);
            printf("Input position: ");
            fflush(stdin);
        }
    }
    fclose(fp);
    return 0;
}