#include <stdio.h>

char* makePhr() {
    char *pStr = "Hello World!";
    return pStr;
}

int main(void) {

    char *phrase = makePhr();
    printf("%s\n", phrase);
    printf("\n%p\n", (void*)&phrase);
    printf("-------------- NUMBER ---------------\n");

    int number = 10;
    int *pNumber = NULL;

    printf("Number's address: %p\n", &number);
    printf("Number's value: %d\n", number);

    pNumber = &number;

    printf("pNumber's address: %p\n", (void*)&pNumber);
    printf("pNumber's size: %zu bytes\n", sizeof(pNumber));
    printf("pNumber's value: %p\n", pNumber);
    printf("Value pointed to: %d\n", *pNumber);

    return 0;
}
