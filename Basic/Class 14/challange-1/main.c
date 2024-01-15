#include <stdio.h>

struct employee {
    char name[20];
    int hireDate;
    float salary;
};

int main(void) {

    struct employee Alex = {"Alex", 2023, 1314.2};   

    struct employee New;

    printf("Insert the contents (Name, Hiredate and Salary):\n");
    scanf("%s", New.name);
    scanf("%i", &New.hireDate);
    scanf("%f", &New.salary);

    printf("Name: %s | Hire Date: %i | Salary: %.2f\n", Alex.name, Alex.hireDate, Alex.salary);
    printf("Name: %s | Hire Date: %i | Salary: %.2f", New.name, New.hireDate, New.salary);

    return 0;
}
