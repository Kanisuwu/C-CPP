#include <stdio.h>

int main(void) {

    int number = 25;
    int *pNumber = &number;

    // If you use this without the pointer * defference
    // it'll instead take the %p pointer hexadecimal address.
    printf("%d", *pNumber);

    return 0;
}
