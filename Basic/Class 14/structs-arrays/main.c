#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int main(void) {

    struct date MyDate[3] = {{ 0, 0, 0 }, { 1, 1, 1990 }, { 25, 12, 2014 }};

    // Each element inside the array will have day, month and year.
    MyDate[0].day = 12;
    MyDate[0].month = 12;
    MyDate[0].year = 2023;

    return 0;
}
