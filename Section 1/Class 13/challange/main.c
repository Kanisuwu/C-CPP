#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    size_t limit = 0;
    char *str = NULL;

    printf("Enter the limit of the string: ");
    scanf("%lu", &limit);

    str = (char*)malloc((limit + 1) * sizeof(char));

    if (!str) {
        printf("\nNot enough memory!\n");
        return 1;
    }

    printf("Enter the string: ");
    scanf("%s", str);

    size_t stringLength = strlen(str);

    if (stringLength > limit) {
        printf("String is bigger than memory allocated.\n");
        free(str);
        return 1;
    }
    
    printf("\nYour string: %s\n", str);

    free(str);

    return 0;
}
