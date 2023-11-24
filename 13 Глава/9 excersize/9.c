#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void) {
    FILE *fp;
    char words[MAX];

    // Make counter
    int word_number, word_id;
    if ((fp = fopen("count.txt", "ab+")) == NULL) {
        word_number = 0;
        word_id = 1;
        itoa(word_number, words, 10);
        fwrite(words, sizeof(char), 41, fp);
    }
    else {
        fread(words, sizeof(char), 41, fp);
        word_number = atoi(words);
        word_id = word_number;
    }
    fclose(fp);

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stdout, "Can't open file \"wordy\".\n");
        exit(EXIT_FAILURE);
    }
    puts("Input words for adding to file; for exit");
    puts("input symbol # in begin of string.");
    while ((fscanf(stdin, "%40s", words)) == 1 && words[0] != '#') {
        fprintf(fp, "%s\n", words);
        ++word_number;
    }
    
    puts("File contents: ");
    rewind(fp);
    for (; fscanf(fp, "%s", words) == 1; ++word_id)
        printf("%d - %s\n", word_id, words);
        //puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error with closing file\n");

    fp = fopen("count.txt", "wb");
    fseek(fp, 0L, SEEK_SET);
    itoa(word_number, words, 10);
    fwrite(words, sizeof(char), 41, fp);

    return 0;
}