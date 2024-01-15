#include <stdio.h>
#include <stdlib.h>

void prtf(FILE* stream, char filter) {
    char str[255];
    while (fgets(str, sizeof(str), stream) != NULL) {
        if (str[0] == filter) {
            puts(str);
            continue;
        }
    }
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Invalid arguments. Gave %i needs 2.\n", (argc - 1));
        exit(1);
    }

    FILE* fl = fopen(argv[1], "r");
    char filter = *argv[2];

    if (!fl) {
        printf("Could not get the file.\n");
        exit(1);
    }

    prtf(fl, filter);

    return 0;
}

