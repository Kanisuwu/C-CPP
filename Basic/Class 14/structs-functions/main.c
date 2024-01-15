#include <stdio.h>

struct person {
    char name[20];
    int power;
};

void isStronger(struct person *p1, struct person *p2) {
    if(p1->power > p2->power) {
        printf("%s is stronger!\n", p1->name);
    }
    else if(p2->power > p1->power) {
        printf("%s is stronger!\n", p2->name);
    }
    else {
        printf("They are equally stronger.\n");
    }
}

int main(void) {

    struct person Person1 = {"Kanisu", 20};
    struct person Person2 = {"Eevee", 21};

    isStronger(&Person1, &Person2);

    return 0;
}
