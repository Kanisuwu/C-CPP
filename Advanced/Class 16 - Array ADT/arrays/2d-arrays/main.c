#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j;
    // In stack
    int A[3][4] = {{0}, {0}, {0}};

    // Partial in heap
    int *B[3];
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    // Full Heap
    int **C;
    C = (int **)malloc(3 * sizeof(int));

    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    for (i = 0; i < 3; ++i) {
        free(C[i]);
        free(B[i]);
    }
    free(C);
    
}
