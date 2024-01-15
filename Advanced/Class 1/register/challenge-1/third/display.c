#include <stdio.h>

extern void display (void) {
    static int i = 0;
    printf("Call number %i\n", i++);
}
