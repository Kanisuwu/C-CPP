#include <stdio.h>
#include <stdarg.h>

// variadic = ...
double average(double num1, double num2, ...) {
    va_list parg;
    double sum = num1 + num2;
    double value = 0.0;
    int count = 2;
    va_start(parg, num2);
    while ((value = va_arg(parg, double)) != 0.0) {
        sum += value;
        count++;
    }
    va_end(parg);
    return sum / count;
}

int main(int argc, char* argv[]) {
    printf("%.1lf\n", average(1.2, 1.1, 12.8, 7.7, 0.0));
    return 0;
}
