#include <stdio.h>

int count = 5;

extern void display();

int main(int argc, char* argv[]) {

    for (int i = 0; i < count; i++) {
        display();
    }

    return 0;
}
