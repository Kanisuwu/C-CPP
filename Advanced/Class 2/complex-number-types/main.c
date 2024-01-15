#include <stdio.h>
#include <complex.h>

int main(void) {
    double complex x1 = 1.0 + 3.0*I;
    double complex y1 = 1.0 + 4.0*I;

    printf("Working with complex numbers:\n");
    printf("x1: %.2f%+.2fi\n", creal(x1), cimag(x1));
    printf("y1: %.2f%+.2fi\n", creal(y1), cimag(y1));

    double complex sum = x1 + y1;

    printf("Sum: %.2f%+.2fi\n", creal(sum), cimag(sum));

    return 0;
}
