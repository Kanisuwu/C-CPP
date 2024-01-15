#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {

    double PI = acos(-1.0);

    double complex x1 = 2.0 + 7.0*(I*I);
    double complex y1 = 1.0 + 3.0*(pow(I, 2));
    double complex euler = exp(I*PI);
    double complex conj_x1 = creal(x1) - cimag(x1)*I;

    printf("(I * I): %.2f%+.2fi\n", creal(x1), cimag(x1));
    printf("pow(I, 2): %.2f%+.2fi\n", creal(y1), cimag(y1));
    printf("Euler: %.2f%+.2fi\n", creal(euler), cimag(euler));
    printf("Conjulgate of I * I: %.2f%+.2fi\n", creal(conj_x1), cimag(conj_x1));

    return 0;
}
