#include <stdio.h>

int main(void) {
    
    int value = 120;
    int *pValue = NULL;

    pValue = &value;

    printf("Address of the pointer: %p\n", &pValue);
    printf("Value of the pointer: %p\n", pValue);
    printf("Pointed to: %d\n", *pValue);

    return 0;
}
