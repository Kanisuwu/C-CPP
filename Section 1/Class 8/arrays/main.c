#include <stdio.h>

int main() {

    int grades[10];
    int count = 10;
    long sum = 0;
    float avarage = 0.0f;

    printf("\nEnter the 10 grades:\n");

    int i;
    for (i = 0; i < count; i++) {
        printf("%d> ", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];
    }

    avarage = (float)sum / count;
    printf("\nAvarage: %g\n", avarage);

    return 0;
}
