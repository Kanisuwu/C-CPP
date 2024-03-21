#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#define UUID_LENGTH 37

/* The node itself. */
struct node {
    char *name;
    char *uuid;
    float price;
    int stock;
    struct node *next;
};

/* Used to be more compact the use of variables. */
struct item {
    char *name;
    char *uuid;
    float price;
    int stock;
};

/*
 * The HEAD pointer needs to be a double pointer
 * for modifying the pointer *head itself instead of its
 * data.
 */
typedef struct node *linked;

/* Does what it says. */
void display_nodes(linked *head);

/*
 * Insert ant te BEGINNING of the linked list.
 * Does not have any problem with null lists
 */
void insert(linked *head, struct item board);

/*
 * Insert at the end of the linked list
 * If the list is null, allocated memory for one element.
 */
void append(linked *head, struct item board);

/* Get the length of the list in how many nodes are there. */
int length(linked *head);

/* Delete an index element. */
int deletel(linked *head, int index);

/* Puts in an INDEX location of the linked list. */
int put(linked *head, int index, struct item board);

/* Removes the last element */
void flast(linked *head);

/* Searches for item name. */
int search(linked *head, char *item);

int genuuid(char *uuid);
