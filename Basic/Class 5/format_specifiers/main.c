#include <stdio.h>

int main() {
    
    int integerVar = 100;
    float floatingVar = 100.5;
    double doubleVar = 2.5e+1;
    char charVar = 'K';
    
    _Bool boolVar = 0;
    
    printf("%i :: %.2f\n", integerVar, floatingVar);
    printf("%.2e\n", doubleVar);
    printf("%g\n", doubleVar);
    printf("%c\n", charVar);
    
    printf("%i\n", boolVar);
    
    return 0;
}
