#include <stdio.h>
#include <stdbool.h>

int main() {

    float kanisu = 20.999f;
    double doubledKanisu = 2.5e+1;

    // from <stdbool.h>
    bool boolVariable = true;

    // from <stdio.h>
    printf("%lf, %f", doubledKanisu, kanisu);

    return 0;
}