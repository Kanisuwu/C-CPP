#include <stdio.h>

int sum(int n) {
    int all = 0;
    if (n > 0) {
        all = n + sum(n - 1);
    }
    return all;
}

int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    else {
        return gcd(num2, num1 % num2);
    }
}

char* strrev(char* str) {
    static int i = 0;
    static char rev[100];

    if (*str) {
        strrev(str + 1);
        rev[i++] = *str;
    }

    return rev;
}

int main(void) {
    printf("Sum of 1 to 5: %i\n", sum(10));
    printf("GCD of 10 and 50: %i\n", gcd(10, 50));
    printf("Reversed 'Goodbye': %s\n", strrev("Goodbye"));
    return 0;
}
