#include <stdio.h>

int main (int argc, char *argv[]) {

    int numberOfArgs = argc;
    char *args1 = argv[0];
    char *args2 = argv[1];

    printf("%d\n", numberOfArgs);
    printf("%s\n", args1);
    printf("%s\n", args2);

    return 0;
}
