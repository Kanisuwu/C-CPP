#include <stdio.h>
#include <stdlib.h>

struct node {
    int *data;
    struct node *next;
};

typedef struct node *linked;

int listsize(linked *head);
void display_noes(linked *head);
void insert(linked *head, int value);
void append(linked *head, int value);
int length(linked *head);

/* Delete an index element. */
int deletel(linked *head, int index);

int put(linked *head, int index, int value);

/* Removes the last element */
void flast(linked *head);

int search(linked *head, int value);

