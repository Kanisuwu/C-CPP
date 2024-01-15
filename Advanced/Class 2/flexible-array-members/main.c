#include <stdio.h>
#include <stdlib.h>

struct myArray {
    int length;
    int array[];
};

int main(void) {

    struct myArray *ptr;
    int i, size = 0;

    printf("Type the size: ");
    scanf("%i", &size);
    if (size <= 0) {
        printf("No memory allocated.\n");
        return 1;
    }

    ptr = (struct myArray *)malloc(sizeof(struct myArray) + size * sizeof(int));
    if (ptr == NULL) {
        printf("Cannot allocate memory.\n");
        return 1;
    }

    for (i = 0; i < size; i++) {
        ptr->array[i] = i + 1;
        printf("Array value: %i\n", ptr->array[i]);
    }


    free(ptr);

    return 0;
};
