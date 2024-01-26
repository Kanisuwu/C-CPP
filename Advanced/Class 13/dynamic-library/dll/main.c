#include <stdio.h>

#include "lib_mylib.h"

void foo(void){
    printf("foo() invoked from shared object (.so|.dll)\n");
}
