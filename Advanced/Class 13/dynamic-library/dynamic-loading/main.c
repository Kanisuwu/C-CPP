#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(void) {

    void *handle = NULL;
    double (*cosine)(double) = NULL;
    char *error = NULL;

    handle = dlopen("/lib/libm.so.6", RTLD_LAZY);

    if (!handle) {
        fputs(dlerror(), stderr);
        exit(EXIT_FAILURE);
    }

    dlerror();

    cosine = dlsym(handle, "cos");

    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(EXIT_FAILURE);
    }
    printf("%.1f\n", (*cosine)(2.0));

    dlclose(handle);

    return 0;
}
