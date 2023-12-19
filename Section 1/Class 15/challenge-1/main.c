#include <ctype.h>
#include <stdio.h>

void copyf(FILE *dest, FILE *src) {
    char character;
    rewind(dest);
    rewind(src);
    while ((character = fgetc(src)) != EOF) {
        fputc(toupper(character), dest);
    }
}

void showf(FILE *stream) {
    char c;
    rewind(stream);
    while ((c = fgetc(stream)) != EOF) {
        printf("%c", c);
    }
}

int main(int argc, char* argv[]) {

    FILE* stream = fopen("./file.txt", "r");
    FILE* copy = NULL;
    
    if (stream != NULL) {
        copy = fopen("./copy.txt", "w+");
    }
    else {
        printf("Error on main stream.");
        return 1;
    }

    copyf(copy, stream);
    fclose(stream);

    remove("./file.txt");
    rename("./copy.txt", "./file.txt");

    showf(copy);

    fclose(copy);
    return 0;
}
