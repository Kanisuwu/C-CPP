#include <math.h>
#include <stdio.h>
#include <string.h>

int binaryC(long long bin) {
    int decimal = 0, i = 0, remainder = 0;
    while (bin != 0) {
        remainder = bin % 10;
        bin = bin / 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

long long tobinary(int num) {
    long long binary = 0;
    int remainder, i = 1;
    while (num != 0) {
        remainder = num % 2;
        num = num / 2;
        binary += remainder * i;
        i = i * 10;
    }
    return binary;
}

int main(void) {
    long long bin = 1100000;
    int decimal = 5;
    printf("B to D: %i\n", binaryC(bin));
    printf("D to B: %lld\n", tobinary(decimal));
    return 0;
}
