#include <stdio.h>

static double onlyHere;
extern float entireProgram;

static int accessOnlyHere(void) {
    return 20;
}

int main(void) {

    int temp;
    static float permanent;
    register int x;

    return 0;
}
