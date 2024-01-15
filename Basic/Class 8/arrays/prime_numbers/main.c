#include <stdio.h>

int main(void) {

    int primesArray[100] = {2, 3};
    int index = 2;

    int prime, i;


    for (prime = 5; prime <= 100; prime += 2) {
        _Bool isPrime = 1;
        for (i = 1; isPrime && prime/primesArray[i] >= primesArray[i]; i++) {
            if (prime % primesArray[i] == 0) {
                isPrime = 0;
            }
        }

        if (isPrime) {
            primesArray[index] = prime;
            index++;
        }
    }

    for (i = 0; i < 100; i++) {
        printf("%d ", primesArray[i]);
    }

    return 0;
}
