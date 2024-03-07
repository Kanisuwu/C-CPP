#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void foo(int **ptr) {
    int a = 5;
    **ptr = a;
}

int main(int argc, char* argv[]) {

    int i = 10;
    int var = 2;
    int *var_ptr = &var;
    int *var_ptr_2 = &i;
    int **var_ptr_ptr = &var_ptr;

    printf("Value of the double pointer: %i\n", **var_ptr_ptr);

    *var_ptr_ptr = var_ptr_2;

    printf("Value of the double pointer: %i\n", **var_ptr_ptr);
    
    /*
     * ----- PART 2 -----
     */ 

    printf("\n");
    int *ptr = NULL;

    ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    foo(&ptr);

    printf("Refference of ptr: %d\n", *ptr);

    free(ptr);

    return 0;
}
