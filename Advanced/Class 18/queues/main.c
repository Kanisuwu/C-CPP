#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct queue {
    int *list;
    int length;
    int size;
    int max;
};

int enqueue(struct queue **qu, int value) {
    struct queue *ptr = *qu;
    if (!ptr) {
        ptr = (struct queue *)malloc(sizeof(struct queue));
        if (!ptr)
            return -1;
        ptr->length = 1;
        ptr->size = 1;
        ptr->list = (int *)malloc(sizeof(int) * ptr->size);
        if (!ptr->list)
            return -1;
        ptr->list[0] = value;
        ptr->max = 1;
        *qu = ptr;
        return 0;
    }
    if (ptr->size >= ptr->max)
        return -1;
    ptr->list = realloc(ptr->list, sizeof(int) * ++ptr->size);
    for (int i = ptr->length; i > 0; i--) {
        ptr->list[i] = ptr->list[i - 1];
    }
    ptr->list[0] = value;
    ptr->length++;
    *qu = ptr;
    return 0;
}

int dequeue(struct queue **qu) {
    int temp;
    struct queue *ptr = *qu;
    if(!ptr)
        return -1;
    temp = ptr->list[ptr->length - 1];
    if (ptr->size > 1) {
        ptr->list = realloc(ptr->list, sizeof(int) * --ptr->size);
        ptr->length--;
    }
    else {
        free(ptr->list);
        free(ptr);
        ptr = NULL;
    }
    *qu = ptr;
    return temp;
}

int display(struct queue **qu) {
    struct queue *ptr = *qu;
    if (!ptr) {
        printf("[/]\n");
        return -1;
    }
    if (!ptr->list) {
        printf("[X]\n");
        return -1;
    }
    printf("[ ");
    for (int i = 0; i < ptr->length; i++) {
        printf("%d ", ptr->list[i]);
    }
    printf("]\n");
    return 0;
}

int main(void) {
    return 0;
}
