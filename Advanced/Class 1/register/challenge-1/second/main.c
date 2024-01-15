#include <stdio.h>

int sum(int num) {
    static int perm = 0;
    perm += num;
    return perm;
}

int main(void) {

    printf("%d\n", sum(25));
    printf("%d\n", sum(25));
    return 0;
}
