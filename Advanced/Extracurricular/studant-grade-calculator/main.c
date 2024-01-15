#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[30];
    double grades[3];
    double average;
};

void infoStudent(struct student *student) {

    int i;
    double sum = 0.0;

    printf("Name the student: \n");
    scanf("%s", student->name);

    while (strlen(student->name) < 2) {
        printf("Enter a valid name: ");
        scanf("%s", student->name);
    }

    printf("Type the three grades: ");
    scanf("%lf %lf %lf", &student->grades[0], &student->grades[1], &student->grades[2]);

    for (i = 0; i < 3; i++) {
        if (student->grades[i] < 0) {
            student->grades[i] = 0.0;
        }
        sum += student->grades[i];
    }

    student->average = (sum / 3);

    printf("\n");

}

void prtinfo(struct student *student) {
    printf("--------------------------------\n");
    printf("Name: %s\n", student->name);
    printf("Grades: [%.2f] [%.2f] [%.2f]\n", student->grades[0], student->grades[1], student->grades[2]);
    printf("Average ---> %.2f\n", student->average);
}

int main(int argc, char* argv[]) {

    int i, many = 0;
    printf("How many students exists: ");
    scanf("%i", &many);
    if (many < 1) {
        printf("\nThere are no students.\n");
        return 1;
    }

    struct student *students = NULL;
    students = (struct student *)malloc(many * sizeof(struct student));

    if (students == NULL) {
        printf("\n>>> COULD NOT ACCESS MEMORY! <<<\n");
        return 1;
    }

    for (i = 0; i < many; i++) {
        infoStudent(&students[i]);
    }

    for (i = 0; i < many; i++) {
        prtinfo(&students[i]);
    }

    free(students);

    return 0;
}
