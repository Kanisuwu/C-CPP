#include <stdio.h>

int main(void) {
    const double PI = 3.141592654;

    // Cannot change the vlaue of indexes of array.
    const int days[12] = {1, 2, 3, 4, 5};

    // points to a constant value
    // same as float const *pf
    const float *pf;

    // points to a constant address
    float *const pt;

    // tells the compiler to optimize for volatile variable
    volatile int vol = 10;

    // For the duration of the scope
    // These pointers will never access the same value
    int *restrict ptr_a;
    int *restrict ptr_b;
    // Use for pointing to integers inside an array is mutually exclusive
}
