#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

struct {
    char *name;
    _Bool isPowered;
} manufacturer;

int main(void) {

    struct date Today = {12, 12, 2023};

    manufacturer.name = "ASUS";
    manufacturer.isPowered = 1;

    printf("%d / %d / %d\n", Today.day, Today.month, Today.year);
    printf("Manufacturer: %s\n", manufacturer.name);

    return 0;
}
