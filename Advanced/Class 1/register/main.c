#include <stdio.h>

int main(void) {
    // cannot use in global scope
    register int x;
    for (x = 1; x < 15; x++) {
        printf("\n%d", x);
    }

    return 0;
}
