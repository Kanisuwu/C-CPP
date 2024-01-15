#include <stdio.h>
#include <stdlib.h>

void check_file(FILE* fl) {
    if (!fl) {
        printf("Could not get the file.\n");
        printf("Exiting the program...\n");
        exit(0);
    }
}

int main(int argc, char* argv[]) {

    FILE *fl = NULL;

    char terminator;
    
    if (argv[1]) {
        fl = fopen(argv[1], "r");
        terminator = EOF;
        check_file(fl);
    }
    else {
        terminator = '\n';
        char ch;
        int words = 0, characters = 0;
        while ((ch = fgetc(stdin)) != terminator) {
            if ((ch == ',') || (ch == ' ')) {
                words += 1;
            }
            characters += 1;
        }
        printf("Number of words: %i\n", words);
        printf("Number of characters: %i\n", characters);
        fclose(stdin);
    }
    return 0;
}
