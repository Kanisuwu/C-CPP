#include <stdio.h>

void setbit(int *num, int position) {
    *num = (1 << position) | *num;
}

int main(int argc, char* argv[]) {
    int num = 10, position = 2;
    printf("Number before the set: %i\n", num);
    printf("%b\n", num);
    setbit(&num, position);
    printf("Number after the set: %i\n", num);
    printf("%b\n", num);
    
    return 0;
}
