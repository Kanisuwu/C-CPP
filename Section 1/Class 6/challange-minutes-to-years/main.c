#include <stdio.h>

int main() {
    int minutes = 0;
    double minutesInYear = 60 * 24 * 365;

    printf("Type how many minutes you want to convert: ");
    scanf("%d", &minutes);

    double years = minutes / minutesInYear;
    double days = 365 / years;

    printf("Minutes: %d\n", minutes);
    printf("Days: %g\n", days); 
    printf("Years: %g\n", years);
}
