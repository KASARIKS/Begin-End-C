#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    if ((fp = fopen(argv[2], "r")) == NULL) {
        printf("File doesn't exists!\n");
    } else {
        char line[1000];
        while ((fgets(line, 1000, fp)) != NULL)
            if (strstr(line, argv[1]))
                printf("%s\n", line);
    }
    return 0;
}