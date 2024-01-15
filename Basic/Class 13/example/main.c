#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *str = NULL;

    // Initial memory allocation
    str = (char*)malloc(15 * sizeof(char));
    strcpy(str, "jason");
    printf("String = %s\n", str);
    printf("Address = %p\n", str);
    printf("---------------------\n");

    /* Realocating memory */
    str = (char*)realloc(str, 25 * sizeof(char));
    strcat(str, ".com");
    printf("String = %s\n", str);
    printf("Address = %p\n", str);

    free(str);
    str = NULL;

    return 0;
}
