#include <stdio.h>

int main(void) {

    int hoursWorked;
  
    printf("Enter how many hours you work weekly: ");
    scanf("%d", &hoursWorked);

    double payRate = hoursWorked > 40 ? 18.0 : 12.0;

    double taxes = 300 * 0.15;
    double grossPay = hoursWorked * payRate;

    if (grossPay <= 300) {
        taxes = grossPay * 0.15;
    } else if (grossPay > 300 && grossPay <= 450) {
        taxes = 300 * 0.15;
        taxes += (grossPay - 300) * 0.2;
    } else if (grossPay > 450) {
        taxes = 300 * 0.15;
        taxes += 150 * 0.2;
        taxes += (grossPay - 450) * 0.25;
    }


    double netPay = grossPay - taxes;

    printf("Gross pay: %g\n", grossPay);
    printf("Pay Rate per Hour: %g\n", payRate);
    printf("Taxes: %g\n", taxes);
    printf("Net Pay: %g\n", netPay);

    return 0;
}
   
