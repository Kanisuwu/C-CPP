#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    int uuid;
    float price;
    int stock;
    struct node *next;
};

struct item {
    char *name;
    int uuid;
    float price;
    int stock;
};

typedef struct node *linked;

void display_nodes(linked *head) {
    struct node *current = *head;
    while (current != NULL) {
        printf("---------------------\n");
        printf("(Name: %s\n", current->name);
        printf("UUID: %d\n", current->uuid);
        printf("Price: %.2f\n", current->price);
        printf("Stock: %d)\n", current->stock);
        current = current->next;
    }
    printf("---------END---------\n");
}

void insert(linked *head, struct item board) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    /* Initializes all variables of the node */
    new_node->name = malloc(sizeof(board.name));
    strcpy(new_node->name, board.name);
    new_node->uuid = board.uuid;
    new_node->price = board.price;
    new_node->stock = board.stock;

    new_node->next = *head;
    *head = new_node;
}

void append(linked *head, struct item board) {
    linked current = *head;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (*head != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        
        /* Initialize the node */
        new_node->name = malloc(sizeof(board.name));
        strcpy(new_node->name, board.name);
        new_node->uuid = board.uuid;
        new_node->price = board.price;
        new_node->stock = board.stock;
    }
    else {
        *head = new_node;
        (*head)->name = (char *)malloc(sizeof(board.name));
        strcpy((*head)->name, board.name);
        (*head)->uuid = board.uuid;
        (*head)->price = board.price;
        (*head)->stock = board.stock;
    }
}

int length(linked *head) {
    int len = 0;
    struct node *current = *head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}

int deletel(linked *head, int index) {
    struct node *prev = NULL;
    struct node *current = *head;
    int i;
    int len = length(head);
    if (*head == NULL)
        return -1;
    if (index < 0 || index >= len)
        return -1;
    if (index == 0) {
        *head = (*head)->next;
        free(current->name);
        free(current);
        return 0;
    }
    for(i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current->name);
    free(current);
    return 0;
}

int put(linked *head, int index, struct item board) {
    struct node *prev = NULL;
    struct node *current = *head;
    int i;
    int len = length(head);
    if (*head == NULL && index > 0)
        return -1;
    if (index < 0 || index >= len)
        return -1;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (index == 0) {
        insert(head, board);
        free(new_node);
        return 0;
    }
    for(i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = new_node;
    new_node->next = current;
    new_node->name = (char *)malloc(sizeof(board.name));
    strcpy(new_node->name, board.name);
    new_node->uuid = board.uuid;
    new_node->price = board.price;
    new_node->stock = board.stock;
    return 0;
}

void flast(linked *head) {
    struct node *prev = *head;
    struct node *current = *head;
    if (*head == NULL) {
        return;
    }
    if ((*head)->next != NULL) {
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current->name);
        free(current);
    }
    else {
        free((*head)->name);
        free(*head);
        *head = NULL;
    }
}

_Bool search(linked *head, char *item) {
    _Bool status = 0;
    struct node *current = *head;
    while (current != NULL) {
        if (strcmp(current->name, item) == 0) {
            status = 1;
            break;
        }
        current = current->next;
    }
    return status;
}
