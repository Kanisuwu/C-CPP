#include <stdio.h>

int main(void) {

    int num = 25;
    // Address cannot be changed.
    // If used const *pNum, then the value cannot be changed.
    const int *const pNum = &num;

    return 0;
}
