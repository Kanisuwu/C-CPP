#include <stdio.h>
#include <stdarg.h>

double add_num(int num_args, ...) {
    if (num_args < 2) {
        return 0;
    }
    double sum = 0;
    va_list args;
    va_start(args, num_args);
    for (int i = 0; i < num_args; i++) {
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum;
}

double average_num(double num1, double num2, ...) {
    va_list args;
    va_start(args, num2);
    double sum = num1 + num2; 
    double average, number;
    int count = 2;
    while ((number = va_arg(args, double)) != 0.0) {
        sum += number;
        count++;
    }
    va_end(args);
    average = sum / count;
    return average;
}

int print(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vfprintf(stdout, fmt, args);
    va_end(args);
    return ret;
}

int main(int argc, char* argv[]) {
    printf("Sum of 10.7, 5.6 and 9.9: %.1f\n", add_num(3, 10.7, 5.6, 9.9));
    printf("Average is: %.1f\n", average_num(10.7, 5.6, 9.9, 0.0));
    print("This is what it did: %.1f / 3\n", add_num(3, 10.7, 5.6, 9.9));
    return 0;
}
