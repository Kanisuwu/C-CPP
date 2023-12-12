#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

void concat(char str1[], char str2[], char result[]) {
    int i;

    int str1_size = stringLength(str1);
    int str2_size = stringLength(str2);

    for (i = 0; i < str1_size; ++i) {
        result[i] = str1[i];
    }

    for (i = str1_size; i < (str2_size + str1_size); ++i) {
        result[i] = str2[i - str1_size];
    }

}

_Bool compare(char str1[], char str2[]) {
    _Bool isEqual = 1;
    int i;

    int str1_size = stringLength(str1);

    for (i = 0; i < str1_size+1; ++i) {
        if (str1[i] != str2[i]) {
            isEqual = 0;
        }
    }

    return isEqual;

}

int main(int argc, char* argv[]) {

    char str1[] = "Hello!";
    char str2[] = "Hello!";
    char result[50];

    int length = stringLength(str1);

    concat(str1, str2, result);

    _Bool equality = compare(str1, str2);

    printf("Length of \"%s\": %d\n", str1, length);
    printf("Concat string: %s\n", result);
    printf("Is \"%s\" equal to \"%s\"? %d\n", str1, str2, equality);

    return 0;
}
