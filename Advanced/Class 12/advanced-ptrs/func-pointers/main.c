#include <stdio.h>

int power(int value) {
    return value * value;
}

// Or use a typedef

typedef int(*pf)(int);

int main(void) {
    int (*pFunction)(int) = NULL;
    pFunction = power;

    pf pFunction2 = NULL;
    pFunction2 = power;

    int value = pFunction(5);
    int value2 = pFunction2(2);
    printf("Power of 5: %i\n", value);
    printf("Power of 2: %i\n", value2);
    return 0;
}
