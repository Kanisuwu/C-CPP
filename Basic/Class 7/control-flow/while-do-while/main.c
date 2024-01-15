#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));
    // 0-20 Inclusive
    int randNumber = rand() % (20+1);

    int number = 0;
    int tries = 5;

    printf("\nYou have to guess a number between 0 and 20.");
    printf("\n------------------");
    printf("\nYou have 5 tries.");
    printf("\nGuess a number: ");
    scanf("%d", &number);

    while (tries > 0) {
        if (number == randNumber) {
            printf("\nYou won!\n");
            printf("The number was: %d\n", randNumber);
            break;
        }
        tries--;
        if (tries == 0) {
            printf("\nYou lost the game.\n");
            printf("The number was: %d\n", randNumber);
            break;
        }
        printf("\nWrong. Try again.");
        printf("\nYou have %d tries left.", tries);
        printf("\nGuess the number: ");
        scanf("%d", &number);

    }

    return 0;
}
