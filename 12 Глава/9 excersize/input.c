#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

char** input(int *number_words) {
    printf("Input number of words: ");
    while (scanf("%d", number_words) != 1) {
        printf("WRONG OUTPUT!\n");
        printf("Input number of words: ");
        fflush(stdin);
    }
    printf("Input %d words: ", *number_words);
    char** words = (char**)malloc(sizeof(char*)*(*number_words));
    fflush(stdin);
    char *str = inputString(stdin, 10);
    words[0] = strtok(str, " ");
    for (int i = 1; i < *number_words; ++i) {
        words[i] = strtok(NULL, " ");
    }
    return words;
}