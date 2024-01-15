#include <stdio.h>

int main(int argc, char* argv[]) {

    int year = 2010;

    // Loop quantifiers
    int i, j;

    float average;
    float averageYearly;

    float yearlyRainfall[5];
    float monthlyRainfall[12];

    float rainfall[5][12] = {
        {7.3, 7.3, 4.9, 3.0, 2.3, 5.6, 0.9, 0.3, 0.5, 1.7, 1.6, 6.7},
        {2.3, 7.3, 4.9, 2.0, 2.3, 0.6, 1.3, 0.3, 0.5, 1.7, 3.6, 6.7},
        {7.3, 8.3, 4.9, 3.0, 2.3, 0.6, 2.2, 0.3, 0.5, 1.7, 3.6, 6.7},
        {7.3, 7.3, 4.9, 0.1, 2.3, 0.6, 0.2, 0.3, 1.5, 1.7, 13.6, 6.7},
        {1.3, 7.3, 4.9, 0.7, 2.3, 0.6, 1.2, 0.3, 5.5, 1.7, 3.6, 6.7},
    };

    printf("YEAR | RAINFALL (inches)\n");

    // Rainfall avevage
    for (i = 0; i < 5; i++) {
        average = 0;
        for (j = 0; j < 12; j++) {
            average += rainfall[i][j];
        }

        yearlyRainfall[i] = average;
        
        printf("%d  %.2f\n", year, yearlyRainfall[i]);
        year++;
    }

    // Yearly Average
    for (i = 0; i < 5; i++) {
        averageYearly += yearlyRainfall[i];
    }

    printf("\nYearly average: %.2f\n", averageYearly/5);
    printf("\nMONTHLY AVERAGES\n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

    // Monthly Average
    for (i = 0; i < 12; i++) {
        average = 0;
        for (j = 0; j < 5; j++) {
            average += rainfall[j][i];
        }
        monthlyRainfall[i] = average;
        printf("%.1f ", monthlyRainfall[i]/5);
    }


    return 0;
}
