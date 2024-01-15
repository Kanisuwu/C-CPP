#include <stdio.h>
#include <string.h>

union power {
    unsigned int level;
    char technique[20];
    char type[20];
};

// Anonymous Union
union {
    int count;
} data;

struct energy {
    char technique[20];
    char type[20];
};

int main(void) {

    union power kanisu = {.type = "Chaos"};
    union power *kanis_ptr = &kanisu;
    struct energy eos;
    data.count = 20;

    // 20B
    printf("Memory size occupied by Kanisu: %zu\n", sizeof(*kanis_ptr));
    // 40B
    printf("Memory size occupied by Eos: %zu\n", sizeof(eos));
    printf("Anonymous Value: %i\n", data.count);

    return 0;
}
