#include <stdio.h>

union student {
    char grade;
    int rounded_grade;
    float exact_grade;
};

int main(int argc, char* argv[]) {
    union student kanisu = {.grade = 'B'};
    union student eos = {.grade = 'A'};

    // Will give undefined behavior because unions do not hold all the memory address, only one.
    kanisu.rounded_grade = 7;
    kanisu.exact_grade = 7.7f;
    printf("Kanisu's score: %c | %i | %.1f\n", kanisu.grade, kanisu.rounded_grade, kanisu.exact_grade);
    printf("Union size: %zu\n", sizeof(kanisu));

    // Unions hold the largest data size, so you need to assign and print each data apart.
    printf("\nEos' scores:\n");
    printf("Grade: %c\n", eos.grade);
    eos.rounded_grade = 9;
    printf("Rounded Grade: %i\n", eos.rounded_grade);
    eos.exact_grade = 9.9f; 
    printf("Exact grade: %.1f\n", eos.exact_grade);
    printf("Union's size: %zu\n", sizeof(eos));
}
