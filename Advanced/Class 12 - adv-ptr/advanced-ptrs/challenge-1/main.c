#include <stdio.h>
#include <stdlib.h>

void allocm(int **ptr) {
    *ptr = (int *)malloc(sizeof(int));
}

void grand(int value) {
    int *ptr = NULL;
    allocm(&ptr);
    *ptr = value;
    printf("\nGrand is pointing to: %i\n", *ptr);
    free(ptr);
}

int main(void) {
    int a = 7;
    int *ptr = NULL;
    int **ptr2 = NULL;

    ptr = &a;
    ptr2 = &ptr;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a);
    printf("Value of ptr: %d\n", *ptr);
    printf("Address of ptr: %p\n", ptr);
    printf("Value of ptr2: %p\n", *ptr2);
    printf("Address of ptr2: %p\n", ptr2);

    printf("\nptr2 dereferenced: %i\n", **ptr2);
    grand(14);

    return 0;
}
