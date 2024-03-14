#include <stdio.h>
#include <stdlib.h>
#include "lib/lib_linked.h"

void serialize(linked *root) {
    FILE* fp = fopen("save.conf", "w");
    if (fp == NULL)
        exit(1);
    for (struct node *cur = *root; cur != NULL; cur = cur->next) {
        fprintf(fp, "%d\n", *cur->data);
    }
    fclose(fp);
}

int unserialize(linked *root) {
    int length = 0;
    FILE *fp = fopen("save.conf", "r");
    if (fp == NULL)
        exit(1);
    int value;
    while (fscanf(fp, "%d, ", &value) > 0) {
        append(root, value);
        length++;
    }
    fclose(fp);
    return length;
}

int main(void) {
    struct node *head = NULL;
    struct item new;
    linked *list = &head;

    display_nodes(list);
    flast(list);
}
