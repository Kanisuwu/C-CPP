#include <stdio.h>

int main(void) {

    size_t size = 5;

    int array[size];
    int *ptr = array;
    int sum;

    for (int i = 0; i < size; i++) {
        *ptr = i + 1;
        printf("Index: %i | Value: %i\n", i, *ptr);
        sum += *(ptr++);
    }
    printf("Sum: %i\n", sum);

    return 0;
}
