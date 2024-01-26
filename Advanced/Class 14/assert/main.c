#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *p1, const void *p2) {
    const int i1 = *(const int *) p1;
    const int i2 = *(const int *) p2;
    return i1 - i2;
}

int main(void) {

    // qsort
    
    int data[5] = {54, 100, 2, 3, 77};

    int (*compare)(const void *, const void *) = NULL;
    compare = compare_ints;

    qsort(data, 5, sizeof(int), compare);

    for (int i = 0; i < 5; i++)
        printf("%i: %d\n", i, data[i]);

    return 0;
}

