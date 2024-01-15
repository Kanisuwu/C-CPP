#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // Based on assumption of each int data is 4 bytes. there's 25 spaces for 4 bytes ints.
    // int *pNumber = (int*)malloc(100);

    // Using sizeof to count the size of int and multiply by 25. Better option.
    int *pNumber = (int*)malloc(25 * sizeof(int));

    // Calloc receives the number of items and their size.
    int *pNumber2 = (int*)calloc(25, sizeof(int));

    // malloc returns a >pointer< (address) of type void. So you need to cast it (int*).
    
    // Malloc return null if it can't allocate memory.
    if (!pNumber) {
        // Do stuff
    }

    // Free ther memory every time iit becomes "useless".
    free(pNumber);
    pNumber = NULL;

    free(pNumber2);
    pNumber = NULL;


    return 0;
}
