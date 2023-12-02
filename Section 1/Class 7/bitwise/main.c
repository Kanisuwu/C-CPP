#include <stdio.h>

int main() {
    int A = 61; // 0011 1101
    int B = 13; // 0000 1101
    unsigned int result = 0;

    // Binary equivalent == 0000 1101
    result = A & B;
    // Binary equivalent == 0011 1101
    result = A | B;
    // Binary equivalent == 0011 0000
    result = A ^ B;
    // Binary equivalent == 1100 0010
    result = ~A;
    // Binary equivalent == 0000 0110
    result = B >> 1;
    // Binary equivalent == 1101 0000
    result = B << 4;

    printf("%d\n", result);

    return 0;
}
