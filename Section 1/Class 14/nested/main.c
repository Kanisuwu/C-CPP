#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time {
    int hours;
    int minutes;
    int seconds;
};

struct date {
    int day;
    int month;
    int year;
};

struct person {
    char *first;
    char *last;
};

// nested structures
struct datetime {
    struct date sdate;
    struct time stime;
};

int main(void) {    
    
    // Can even do an array of nested structures.
    struct datetime event;

    event.sdate.day = 12;
    event.sdate.month = 12;
    event.sdate.year = 2023;

    event.stime.hours = 13;
    event.stime.minutes = 50;
    event.stime.seconds = 25;

    struct datetime *eventPtr = &event;



    struct person *Leticia;

    Leticia = (struct person *)malloc(sizeof(struct person));

    Leticia->first = (char*)malloc(8 * sizeof(char));
    Leticia->last = (char*)malloc(7 * sizeof(char));

    strcpy(Leticia->first, "Letícia");
    strcpy(Leticia->last, "Cabral");

    printf("First Letter: %c | Name: %s | Lastname: %s\n", *Leticia->first ,Leticia->first, Leticia->last);

    printf("Day: %i\n", eventPtr->sdate.day);

    free(Leticia->first);
    Leticia->first = NULL;
    free(Leticia->last);
    Leticia->last = NULL;
    free(Leticia);
    
    return 0;
}
