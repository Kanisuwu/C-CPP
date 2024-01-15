#include <stdio.h>

typedef int* i_pointer;

int main(void) {

    int x = 20;
    i_pointer p = &x;

    printf("Value: %i | Address-P: %p", *p, p);

    return 0;
}
