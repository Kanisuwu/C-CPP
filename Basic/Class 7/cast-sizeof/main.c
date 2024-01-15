#include <stdio.h>

int main() {

    printf("Int: %zd\n", sizeof (int));
    printf("Float: %zd\n", sizeof (float));
    printf("Double: %zd\n", sizeof (double));
    printf("Short: %zd\n", sizeof (short));
    printf("Long: %zd\n", sizeof (long));
    printf("Long long: %zd\n", sizeof (long long));
    printf("Long double: %zd\n", sizeof (long double));
    printf("Char: %zd\n", sizeof (char));

    return 0;
}
