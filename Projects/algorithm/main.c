#include <stdio.h>

void bubblesort(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - (i + 1); ++j) {
            int left = array[j];
            int right = array[j + 1];
            if (left > right) {
                array[j] = right;
                array[j + 1] = left;
            }
        }
    }
}

int main(void) {
    int length = 5;
    int array[5] = {5, 8, 2, 22, 17};
    bubblesort(array, length);
    for (int i = 0; i < length; ++i) {
        printf("%i\n", array[i]);
    }
}
