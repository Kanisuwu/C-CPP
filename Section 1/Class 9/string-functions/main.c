#include <stdio.h>
#include <string.h>

void strReverse(char str[]) {
    size_t length = strlen(str);
    char temp[length+1];

    int i;

    strcpy(temp, str);

    for (i = 0; i < length; ++i) {
        str[i] = temp[length - 1 - i];
    }
}

void swap(char str1[], char str2[]) {
    char temp[101];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void bubbleSort(char arr[][101], int length) {
    for (int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 -i; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(void) {
    size_t length = 5;
    char str[101];
    char strArray[5][101] = {"Abacate", "Car", "Buffalo", "Synth", "Lynn"};
    printf("Enter a string to be reversed: ");
    scanf("%100s", str);
    strReverse(str);
    printf("Your reversed string: %s\n", str);

    printf("\n----------UNSORTED----------\n");

    for (int i = 0; i < length; i++) {
        printf("%s\n", strArray[i]);
    }

    bubbleSort(strArray, length);

    printf("\n----------SORTED----------\n");

    for (int i = 0; i < length; i++) {
        printf("%s\n", strArray[i]);
    }


    return 0; 
}
