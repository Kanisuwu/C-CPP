#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    char *str = NULL;
    system("ls -lah .");
    assert((str = getenv("HOME")) != NULL);
    printf("%s\n", str);
    return 0;
}
