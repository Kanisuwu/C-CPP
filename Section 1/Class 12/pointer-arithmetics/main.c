#include <stdio.h>

int main(void) {

    int array[5] = {10, 22, 73 ,14 ,95};
    char *str = "Paralelepipedo";

    int *ptr = array;
    int sum = 0;
    int letterCount = 0;

    for (int i = 0; i < 5; i++) {
        sum += *ptr;
        printf("%d\n", *(ptr++));
    }
    printf("\n%d\n", sum);

    while (*str) {
        letterCount++;
        printf("%c\n", *(str++));
    }
    printf("\nLetter Count: %i\n", letterCount);

    return 0;
}
