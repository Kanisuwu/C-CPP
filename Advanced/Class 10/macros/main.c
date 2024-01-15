#include <stdio.h>
#include <stdlib.h>

// Macro for a constant variable
#define PI 3.14

// Macro that works as a function
#define PX(a, b)\
    printf("Value 1 = %d\n", a);\
    printf("Value 2 = %d\n", b);\
    fprintf(stderr, "Warning, using macros\n");

#define prt(x) #x

#define TOKENCONCAT(x, y) x##y

/*
 * MACROS ARE PRE-PROCESSED! Harder to Debug
 */

int main(int argc, char* argv[]) {
    int x = *argv[1] - '0';
    int y = 5;
    int OK = 0;
    TOKENCONCAT(O, K) = 2;
    printf("Token concat value: %i\n", OK); 
    if (x > 5) {
        fprintf(stderr, "Error on line: %d\n", __LINE__);
        fprintf(stderr, "On function: %s\n", __func__);
        fprintf(stderr, "Quitting program.\n");
        exit(EXIT_FAILURE);
    }
    PX(x, y);
    return 0;
}
