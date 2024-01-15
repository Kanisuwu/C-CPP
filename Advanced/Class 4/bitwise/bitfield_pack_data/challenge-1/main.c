#include <stdio.h>

struct box {
    unsigned int :6;
    unsigned int opaque :1;
    unsigned int border :1;
    unsigned int fill_color: 3;
    unsigned int border_color: 3;
    unsigned int border_style: 2;
};

void check_c(struct box *b, _Bool box) {
    char *mode;
    unsigned int type = 0;
    if (box == 1) {
        mode = "box";
        type = b->fill_color;
    }
    else {
        mode = "border";
        type = b->border_color;
    }
    switch (type) {
        case 0:
            printf("The %s is black.\n", mode);
            break;
        case 1:
            printf("The %s is red.\n", mode);
            break;
        case 2:
            printf("The %s is green.\n", mode);
            break;
        case 3:
            printf("The %s is yellow.\n", mode);
            break;
        case 4:
            printf("The %s is blue.\n", mode);
            break;
        case 5:
            printf("The %s is purple.\n", mode);
            break;
        case 6:
            printf("The %s is cyan.\n", mode);
            break;
        case 7:
            printf("The %s is white.\n", mode);
    }
}

void check_b(struct box *b) {

    switch (b->border_style) {
        case 0:
            printf("The border style is solid.\n");
            break;
        case 1: 
            printf("The border style is dotted.\n");
        case 2:
            printf("The border style is dashed.\n");
    }

    if (b->border) {
        printf("Border shown.\n");
    }
    else {
        printf("Border hidden.\n");
    }
}

int main(int argc, char* argv[]) {

    struct box myBox = {0};

    myBox.opaque = 1;
    myBox.border = 1;
    myBox.fill_color = 3;
    myBox.border = 1;
    myBox.border_color = 2;
    myBox.border_style = 2;

    printf("------- ORIGINAL -------\n");

    if (myBox.opaque) {
        printf("Box is opaque.\n");
    }
    else {
        printf("Box is transparent.\n");
    }

    check_c(&myBox, 0);
    check_c(&myBox, 1);
    check_b(&myBox);

    printf("------- MODIFIED -------\n");

    myBox.opaque = 0;
    myBox.border = 1;
    myBox.fill_color = 7;
    myBox.border = 1;
    myBox.border_color = 5;
    myBox.border_style = 0;

    if (myBox.opaque) {
        printf("Box is opaque.\n");
    }
    else {
        printf("Box is transparent.\n");
    }

    check_c(&myBox, 0);
    check_c(&myBox, 1);
    check_b(&myBox);
    return 0;
}
