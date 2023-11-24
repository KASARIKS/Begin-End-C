#include "check_args.h"

int check_args(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    return 0;
}