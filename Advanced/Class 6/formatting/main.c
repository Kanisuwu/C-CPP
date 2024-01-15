#include <stdio.h>
#include <stdbool.h>

bool isEven(int num) {
    if ((num % 2) == 0) {
        return true;
    }
    return false;
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if ((num % i) == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {

    int number;
    FILE* fl = fopen("numbers.txt", "r");

    if (!fl) {
        printf("Could not open the >numberx.txt<\n");
        return 1;
    }

    while (fscanf(fl, "%d", &number) != EOF) {
        if (isPrime(number)) {
            printf("%d is prime\n", number);
        }
        else if (isEven(number)) {
            printf("%d is even\n", number);
        }
        else {
            printf("%d is odd\n", number);
        }
    }

    fclose(fl);

    return 0;
}
