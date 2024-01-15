#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char character;
    FILE *stream = NULL;
    int first = 0, last = 0, sum = 0;

    stream = fopen(argv[1], "r");

    if (!stream) {
        printf("Unknown file.\n");
        return -1;
    }

    while ((character = fgetc(stream)) != EOF) {
        if (character >= '1' && character <= '9') {
            if (!first) first = character-'0';
            last = character-'0';
        }
        else if (character == '\n') {
            sum += (first*10) + last;
            first=last=0;
            continue;
        }
     }
    printf("\n%i\n", sum);
    return 0;
}
