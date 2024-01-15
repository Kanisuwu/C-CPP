#include <math.h>
#include <stdint.h>
#include <stdio.h>

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

long long decToBin(int num) {
    int remainder = 0, i = 1, binary = 0;
    while (num != 0) {
        remainder = num % 2;
        num = num / 2;
        binary += remainder * i;
        i = i * 10;
    }
    return binary;
}

int main(void) {
    int32_t first = 10;
    int32_t second = 11;

    printf("First and second numbers: %lld, %lld\n", decToBin(first), decToBin(second));
    printf("Using ~: %lld %lld\n", decToBin(~first), decToBin((~second)));
    printf("Using &: %lld\n", decToBin((first & second)));
    printf("Using |: %lld\n", decToBin((first | second)));
    printf("Using ^: %lld\n", decToBin((first ^ second)));
    printf("Using >> *2 on first: %lld\n", decToBin(first >> 2));
    printf("Using << *2 on first: %lld\n", decToBin(first << 2));

    return 0;
}
