#include <stdio.h>

// Can be declared as #warning
//#pragma GCC warning "Warning example"
// Can be declared as #error
//#pragma GCC error "What?"
#pragma message "Ok"

int main(void) {

    #ifndef IS_YOU
        #define IS_YOU 1
    #endif

    #if IS_YOU
        printf("Constant is true.\n");
    #else
        printf("Constant is false.\n");
    #endif

    #undef IS_YOU

    return 0;
}
