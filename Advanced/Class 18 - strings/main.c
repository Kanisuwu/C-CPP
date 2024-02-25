#include <stdio.h>

int length(char *string){
    int length = 0;
    while (*(string++) != '\0') {
        length++;
    }
    return length;
}

/* Diff on ASCII table is 32 */
void touppercase(char *string){
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 97 && string[i] <= 122)
            string[i] -= 32;
    }
}

void tolowercase(char *string){
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 65 && string[i] <= 90)
            string[i] += 32;
    }
}

int main(int argc, char* argv[]) {
    char array[] = "WELCOME";
    tolowercase(array);
    printf("%s\n", array);
    return 0;
}
