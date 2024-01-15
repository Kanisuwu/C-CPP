#include <stdio.h>

void showfr(FILE *stream) {

    char c;
    int pos = -2;

    fseek(stream, -2, SEEK_END);

    while (ftell(stream) > 1) {
        fseek(stream, pos--, SEEK_END);
        c = fgetc(stream);
        printf("%c", c);
    }
}

int main(int argc, char *argv[]) {

    char *filepath = "./file.txt";
    FILE *file = fopen(filepath, "r");

    fseek(file, 0, SEEK_END);

    int pos = ftell(file);

    showfr(file);
    fclose(file);

    return 0;
}
