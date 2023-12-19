#include <stdio.h>

int main(void) {

    int return_code = 0;
    FILE *stream = NULL;
    const char *fname = "./file.txt";
    stream = fopen(fname, "r");
    if (!stream) {
        printf("Could not read the file.");
        return_code = 1;
    }

    char string[100];
    char character;
    int lines = 0;

    while ((character = fgetc(stream)) != EOF) {
        if (character == '\n') {
            lines++;
        }
    }

    fseek(stream, 22000, SEEK_SET);

    if (fgets(string, 100, stream) != NULL) {
        printf("%s", string);
    }

    fclose(stream);
    stream = NULL;

    if (!stream) {
        printf("\nFile is closed.\n");
    }

    printf("\nThere is %i lines in that file.\n", lines);

    return return_code;
}
