#include <stdio.h>

char vowel[] = "aAeEiIoOuU";

int length(char *string){
    int length = 0;
    while (*(string++) != '\0') {
        length++;
    }
    return length;
}

/* Diff on ASCII table is 32 */
void touppercase(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 97 && string[i] <= 122)
            string[i] -= 32;
    }
}

void tolowercase(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 65 && string[i] <= 90)
            string[i] += 32;
    }
}

void words(char *str) {
    int i, word = 1;
    char prev;
    for (i = 0; str[i] != '\0'; i++) {
        prev = str[i - 1];
        if (str[i] == ' ' && prev != ' ') {
            word++;
        }
    }
    printf("Words: %d\n", word);
}

_Bool validate(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122))
            return 0;
    }
    return 1;
}

void reverse(char *dest, char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
    }
    i = i - 1;
    for (j = 0; i >= 0; i--, j++) {
        dest[j] = str[i];
    }
    dest[j] = '\0';
}

void reverse_2(char *str) {
    int i, j;
    char temp;
    for (j = 0; str[j] != '\0'; j++) {
    }
    j--;
    for (i = 0; i < j; j--, i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main(int argc, char* argv[]) {
    char array[] = "python";
    printf("Original: %s\n", array);
    reverse_2(array);
    printf("Reversed: %s\n", array);
    return 0;
}
