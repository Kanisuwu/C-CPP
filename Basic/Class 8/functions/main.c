#include <stdio.h>

int greatestCommonDivisor(int num1, int num2) {
    int i, gcd;

    if (num1 < 1 && num2 < 1) {
        return 1;
    }

    if(num1 > num2) {
        for (i = 1; i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
                gcd = i;
            }
        }
    }
    if (num2 > num1) {
        for (i = 1; i < num1; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
                gcd = i;
            }
        }
    }
    return gcd;
}

float absoluteValue(float num) {
    if (num < 0) {
        num = num * (-1);
    }
    return num;
}

float squareRoot(int num) {
    double epsilon = 0.0000001;
    float sqrt = absoluteValue(num) / 2.0;
    if (num < 0) {
        printf("Cannot get square root of numbers less than 0.\n");
        return -1.0;
    }
    while ((sqrt * sqrt - num) >= epsilon) {
        sqrt = 0.5 * (sqrt + absoluteValue(num) / sqrt);
    }
    return sqrt;
}

int main(int argc, char* argv[]) {
    int gcd = greatestCommonDivisor(8, 12);
    float abs = absoluteValue(5);
    float sqrt = squareRoot(3755);
    printf("%d %.2f %f\n", gcd, abs, sqrt);
    return 0;
}
