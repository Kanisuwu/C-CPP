#include <stdio.h>

struct packed_data {
    int count;
    char c;
    unsigned int :3;
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
};

int main(void) {

    struct packed_data data;

    data.type = 7;
    data.f1 = 0;
    data.f2 = 1;
    data.f3 = 1;

    printf("%i\n", data.type);

    return 0;
}
