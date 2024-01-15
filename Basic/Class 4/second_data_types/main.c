#include <stdio.h>
#include <stdbool.h>

int main() {

    // Be careful, 'single quote' means character and "double quote" means strign
    char kanisu;
    kanisu = 'K';

    // Can only assign variables with male and female values from enum SEX.
    enum sex {male, female};
    enum sex mySex = male;
    enum sex anotherSex = female;

    bool isMale = (mySex == anotherSex);

    printf("%d\n", isMale);
    printf("%c\n", kanisu);

    return 0;
}