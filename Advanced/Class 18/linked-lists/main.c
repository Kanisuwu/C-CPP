#include <stdio.h>
#include <stdlib.h>

struct node {
    int *data;
    struct node *next;
};

int listsize(struct node *head) {
    struct node *current = head;
    int size = 0;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void display_nodes(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("(%d) -> ", *current->data);
        current = current->next;
    }
    printf("END\n");
}

void make_node(struct node **head, int value) {
    struct node *current = *head;
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

void flast(struct node **head) {
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

void ch_data(struct node **head) {
    *(*head)->data *= 2;
}

int main(void) {

    struct node *head = NULL;
    struct node **linked = &head;

    int value = 12;
    make_node(linked, value);
    make_node(linked, value * 2);
    make_node(linked, value * 4);
    int size = listsize(head);
    printf("Nodes: %d\n", size);
    display_nodes(head);
    for (int i = 0; i < size; i++)
        flast(&head);

    return 0;
}
