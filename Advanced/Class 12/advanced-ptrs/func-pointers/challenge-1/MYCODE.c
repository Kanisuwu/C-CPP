#include <stdio.h>
#include <stdlib.h>

void show_menu() {
    printf("----- Choose your option -----\n");
    printf("\n");
    printf("1 - add.\n");
    printf("2 - quit.\n");
}

int collect_info() {
    int info = 0;
    printf("Select: ");
    scanf("%i", &info);
    return info;
}

int add(int num1, int num2) { return num1 + num2; }
void quit() { exit(EXIT_SUCCESS); }

typedef int(*FTR)(int);

int main(void){

    int opt = 0;

    int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int array2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    while (1) {
        show_menu();
        opt = collect_info();
    }

    return 0;
}
