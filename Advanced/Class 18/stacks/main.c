#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *list;
    int length;
    int size;
};

int make_stack(struct stack **stk) {
    int initial_size = 1;
    *stk = (struct stack *)malloc(sizeof(struct stack));
    if (stk == NULL) {
        printf("Error while allocating memory for stack [%d].\n", __LINE__);
        return -1;
    }

    (*stk)->size = initial_size;
    (*stk)->length = 0;
    (*stk)->list = (int *)malloc(sizeof(int) * (*stk)->size);

    if ((*stk)->list == NULL) {
        printf("Error while allocating memory for stack list. [%d]\n", __LINE__);
        return -1;
    }
    return 0;
}

int push(struct stack **stk, int value) {
    int i;
    if ((*stk)->length >= (*stk)->size) {
        (*stk)->list = realloc((*stk)->list, sizeof(int) * (++(*stk)->size));
    }
    if ((*stk)->list == NULL) {
        printf("Cannot reallocate memory [%d].\n", __LINE__);
        return -1;
    }
    if ((*stk)->length < 1) {
        (*stk)->list[(*stk)->length++] = value;
        return 0;
    }
    for (i = (*stk)->length; i > 0; i--) {
        (*stk)->list[i] = (*stk)->list[i - 1]; 
    }
    (*stk)->list[0] = value;
    (*stk)->length++;
    return 0;
}

int delete(struct stack **stk) {
    struct stack *ptr = *stk;
    free(ptr->list);
    free(ptr);
    ptr = NULL;
    *stk = ptr;

    return 0;
}

int pop(struct stack **stk) {
    int i, temp;
    struct stack *list = *stk;
    if (list->length < 1 || list->size < 1)
        return -1;
    temp = list->list[0];
    for (i = 0; i < list->length - 1; i++) {
        list->list[i] = list->list[i + 1];
    }
    list->length--;
    if (list->size > 1) {
    list->list = realloc((*stk)->list, sizeof(int) * --list->size);
    }
    *stk = list;
    return temp;
}

void display(struct stack **stk) {
    struct stack *ptr = *stk;
    printf("[");
    for (int i = 0; i < ptr->length; i++) {
        printf(" %d", ptr->list[i]);
    }
    printf(" ]\n");
}


int main(void) {
    struct stack *stk = NULL;
    int value = 2;
    make_stack(&stk);
    push(&stk, value);
    push(&stk, value * 2);
    push(&stk, value * 3);
    display(&stk);
    int popped = pop(&stk);
    pop(&stk);
    pop(&stk);
    printf("Pop: %d\n", popped);
    display(&stk);
    printf("Size: %d\nLength: %d\n", stk->size, stk->length);
    delete(&stk);
    if (stk == NULL) {
        printf("Stack sucessfully deallocated.\n");
    }
    return 0;
}
