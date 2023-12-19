#include <stdio.h>

int main(int argc, char* argv[]){

    FILE *fl;
    int ch;

    fl = fopen("./file.txt", "w+");
    for (ch = 33; ch <= 100; ch++) {
        fputc(ch, fl);
    }

    fclose(fl);
    fl = NULL;

    return 0;
}
