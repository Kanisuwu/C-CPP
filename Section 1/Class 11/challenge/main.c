#include <stdio.h>

void square(int *num) {
    *num = *num * *num;
}

int main(void) {
    int num = 10;
    printf("Before the square: %d\n", num);
    square(&num);
    printf("After the square: %d\n", num);
    return 0;
}
