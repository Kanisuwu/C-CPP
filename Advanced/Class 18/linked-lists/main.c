#include <stdio.h>
#include <stdlib.h>

struct node {
    int *data;
    struct node *next;
};

typedef struct node *linked;

int listsize(linked *head) {
    struct node *current = *head;
    int size = 0;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void display_nodes(linked *head) {
    struct node *current = *head;
    while (current != NULL) {
        if (*current->data)
            printf("(%d) -> ", *current->data);
        else
            printf("(NULL) -> ");
        current = current->next;
    }
    printf("END\n");
}

void insert(linked *head, int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = (int *)malloc(sizeof(int));
    *new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void append(linked *head, int value) {
    linked current = *head;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (*head != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        current->next->data = (int *)malloc(sizeof(int));
        *current->next->data = value;
    }
    else {
        *head = new_node;
        (*head)->data = (int *)malloc(sizeof(int));
        *(*head)->data = value;
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

int delete(linked *head, int index) {
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
        free(current->data);
        free(current);
        return 0;
    }
    for(i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current->data);
    free(current);
    return 0;
}

int put(linked *head, int index, int value) {
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
        insert(head, value);
        free(new_node);
        return 0;
    }
    for(i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = new_node;
    new_node->next = current;
    new_node->data = (int *)malloc(sizeof(int));
    *new_node->data = value;
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
        free(current->data);
        free(current);
    }
    else {
        free((*head)->data);
        free(*head);
        *head = NULL;
    }
}

int search(linked *head, int value) {
    _Bool status = 0;
    struct node *current = *head;
    while (current != NULL) {
        if (*current->data == value)
            status = 1;
        current = current->next;
    }
    return status;
}

int main(void) {

    linked list = NULL;
    linked *head = &list;

    int value = 2;
    append(head, value);
    append(head, value * 4);
    put(head, 1, value * 2);
    display_nodes(head);
    int len = length(head);
    for (int i = 0; i < len; i++)
        flast(head);
    display_nodes(head);

    return 0;
}
