#include <stdio.h>

void swap(int *a, int *b) {
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {

    int i = 10;
    float f = 2.34f;
    char ch = 'k';

    int array[8] = {1, 2, 3, 4, 5, 6, 7, 0};

    void *vptr;

    vptr = &i;
    printf("Value of i: %d\n", *(int *)vptr);

    vptr = &f;
    printf("Value of f: %.2f\n", *(float *)vptr);

    vptr = &ch;
    printf("Value of ch: %c\n", *(char *)vptr);

    vptr = array;
    for (i = 0; i < 8; ++i) {
        printf("Number: %d\n", *((int*)vptr + i));
    }

    int a = 10;
    int b = 100;
    printf("\nBEFORE THE SWAP\n");
    printf("%d\n", a);
    printf("%d\n", b);
    printf("\nAFTER THE SWAP\n");
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}
