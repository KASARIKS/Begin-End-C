#include "check_args.h"
#include "count_syms.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (check_args(argc, argv)) {
        printf("Something wrong with arguments of comand line!\n");
    } else {
        if (argc == 2) {
            char str[80];
            printf("Input string: ");
            char ch;
            for (int i = 0; (ch = getchar()) != '\n'; ++i) {
                str[i] = ch;
            }
            int count = 0;
            for (int i = 0; i < strlen(str); ++i) if (str[i] == argv[1][0]) ++count;
            printf("STring: %d\n", count);
        }
        for (int i = 2; i < argc; ++i) {
            int res = count_syms(argv[i], argv[1][0]);
            if (res == -1) printf("%s: Doesn't exist\n", argv[i]);
            else printf("%s: %d\n", argv[i], count_syms(argv[i], argv[1][0]));
        }
    }
    return 0;
}