#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/lib_linked.h"

#define WORD_LENGTH 64

void serialize(linked *root) {
    FILE* fp = fopen("save.conf", "w");
    if (fp == NULL)
        exit(1);
    for (struct node *cur = *root; cur != NULL; cur = cur->next) {
        fprintf(fp, "{\n");
        fprintf(fp, "\tname: \"%s\",\n", cur->name);
        fprintf(fp, "\tuuid: \"%s\",\n", cur->uuid);
        fprintf(fp, "\tprice: \"%f\",\n", cur->price);
        fprintf(fp, "\tstock: \"%d\"\n", cur->stock);
        fprintf(fp, "},\n");
    }
    fclose(fp);
}

/* Reads "save.conf" and builds a linked list with each object. */
int unserialize(linked *root) {
    _Bool status = 0;
    int length = 0;
    struct item board = {
        .name = NULL,
        .uuid = NULL,
        .price = 0,
        .stock = 0
    };

    FILE *fp = fopen("save.conf", "r");
    if (fp == NULL)
        exit(1);

    char name[32];
    int namelen = 0;
    while (fscanf(fp, "{\n") != EOF) {
        if (!fscanf(fp, "\tname: \"%[^\"]\",\n", name))
            break;

        /* Allocates the right sized memory for board.name and copies the string */
        namelen = strlen(name);
        board.name = (char *)malloc(namelen + 1);
        if (board.name == NULL) {
            printf("Could not allocated memory.\n");
            break;
        }
        strcpy(board.name, name);

        /* Reads the last variables and continues the cicle */
        if (fscanf(fp, "\tuuid: \"%[^\"]\",\n", name)) {
            board.uuid = malloc(UUID_LENGTH);
            strcpy(board.uuid, name);
        }
        else {
            status = 1;
        }
        if (!fscanf(fp, "\tprice: \"%f\",\n", &board.price))
            status = 1;
        if (!fscanf(fp, "\tstock: \"%d\"\n", &board.stock))
            status = 1;
        fscanf(fp, "},\n");
        if (status) {
            printf("Error while loading item [%d]\n", length);
            length++;
            continue;
        }

        append(root, board);
        length++;
    }
    fclose(fp);
    return length;
}

void swap(struct node **A, struct node **B) {
    struct node *temp = *A;
    *A = *B;
    *B = temp;
}

void swapNodes(linked *list, char *x, char *y) {
    linked *A = NULL, *B = NULL;

    if (strcmp(x, y) == 0)
        return;

    while (*list) {
        if (strcmp((*list)->name, x) == 0) {
            A = list;
        }
        else if (strcmp((*list)->name, y) == 0) {
            B = list;
        }
        list = &((*list)->next);
    }

    if (A && B) {
        swap(A, B);
        swap(&((*A)->next), &((*B)->next));
    }
}

void bubblesort(linked *list, int len) {
    int i, j;
    struct node *curr = *list;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - (i + 1); j++) {
            if (strcmp(curr->name, curr->next->name) > 0) {
                swapNodes(list, curr->name, curr->next->name);
            }
        }
    }
}

/* Asks user for creating it's own item */
struct item *construct() {
    struct item *board = (struct item *)malloc(sizeof(struct item));
    if (!board) {
        printf("Memory error for item.\n");
        exit(1);
    }
    
    board->name = NULL;
    board->uuid = NULL;
    board->price = 0;
    board->stock = 0;

    char temp_name[64];
    char uuid[UUID_LENGTH];
    
    printf("Enter the name: ");
    scanf("%s", temp_name);
    board->name = (char *)malloc((strlen(temp_name) + 1));
    strcpy(board->name, temp_name);
    if (!board->name) {
        printf("Memory error for naming.\n");
        exit(1);
    }

    genuuid(uuid);
    board->uuid = (char *)malloc((strlen(uuid) + 1));
    if (!board->uuid) {
        printf("Memory error for uuid.\n");
        exit(1);
    }
    strcpy(board->uuid, uuid);

    printf("Enter the price: ");
    scanf("%f", &board->price);
    while (board->price < 0) {
        printf("Enter a valid price: ");
        scanf("%f", &board->price);
    }

    printf("Enter the stock: ");
    scanf("%d", &board->stock);
    while (board->stock < 0) {
        printf("Enter a valid stock: ");
        scanf("%d", &board->stock);
    }

    return board;
}

/* MENU FUNCTIONS */

void menu() {
    printf("--------- MENU ---------\n");
    printf("1. Add\n");
    printf("2. Edit\n");
    printf("3. List\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
}

int show(linked *list, char *key) {
    linked *target = NULL;
    int status = 0;
    while (*list) {
        if (strcmp((*list)->name, key) == 0) {
            target = list;
            status = 1;
        }
        list = &((*list)->next);
    }
    if (status) {
        printf("-------------------\n");
        printf("Name: %s\n", (*target)->name);
        printf("UUID: %s\n", (*target)->uuid);
        printf("Price: %.2f\n", (*target)->price);
        printf("Stock: %d\n", (*target)->stock);
        printf("-------------------\n");
    } 
    return status;
}

int edit(linked *list, char *key) {
    linked *target = NULL;
    while (*list) {
        if (strcmp((*list)->name, key) == 0) {
            target = list;
            break;
        }
        list = &((*list)->next);
    }
    if (*target == NULL) {
        printf("Could not find %s item.\n", key);
        return 1;
    }

    char newname[WORD_LENGTH];
    float newprice = 0;
    int newstock = 0;
    int status = 1;

    while (status) {
        printf("Enter the command.\n");
        printf("[1]Name, [2]Price, [3]Stock, [4]Exit: ");
        int command;
        scanf("%d", &command);
        while ((command < 1) && (command > 4)) {
            printf("Invalid command: ");
            scanf("%d", &command);
        }
        switch (command) {
            case 1:
                printf("Enter the new name: ");
                scanf("%s", newname);
                free((*target)->name);
                (*target)->name = (char *)malloc((strlen(newname) + 1));
                if (!(*target)->name) {
                    printf("Could not allocate memory.\n");
                    exit(1);
                }
                strcpy((*target)->name, newname);
                break;
            case 2:
                printf("Enter the new price: ");
                while (scanf("%f", &newprice) != 1) {
                    int c;
                    while (((c = getchar()) != '\n') && (c != EOF));
                    printf("Enter a valid price: ");
                    scanf("%f", &newprice);
                }
                (*target)->price = newprice;
                break;
            case 3:
                printf("Enter the new stock: ");
                while (scanf("%d", &newstock) != 1) {
                    int c;
                    while (((c = getchar()) != '\n') && (c != EOF));
                    printf("Enter a valid stock: ");
                    scanf("%d", &newstock);
                }
                (*target)->stock = newstock;
                break;
            case 4:
                printf("Exitting edit.\n");
                status = 0;
                break;
        }
    }

    return 0;
}

/*
 *
 * uwu
 *
 */

int main(void) {
    struct node *head = NULL;
    linked *list = &head;

    system("clear");
    menu();
    unserialize(list);

    int command;
    int status = 1;
    struct item *board = NULL;

    while (status) {
        printf("[]> ");
        while (scanf("%d", &command) != 1) {

            /* Remember to clear the buffer */
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            /* Info feedback */
            printf("Command Unknown. Type '0' for help.\n");
            printf("[]> ");
        };

        switch (command) {
            /* Clear & Menu */
            case 0:
                system("clear");
                menu();
                break;
            /* Add */
            case 1:
                board = construct();
                append(list, *board);
                free(board);
                serialize(list);
                board = NULL;
                break;
            /* Edit */
            case 2:
                printf("[EDIT]> ");
                char *search = malloc(WORD_LENGTH);
                scanf("%s", search);
                edit(list, search);
                serialize(list);
                show(list, search);
                break;
            /* Search */
            case 3:
                printf("[SEARCHING]> ");
                char *search_name = malloc(WORD_LENGTH);
                scanf("%s", search_name);
                if (strcmp(search_name, "all") == 0) {
                    display_nodes(list);
                }
                else if (!show(list, search_name)) {
                    printf("Item does not exist.\n");
                }
                free(search_name);
                break;
            /* Quit */
            case 5:
                status = 0;
                printf("Quitting.\n");
                break;
            /* Unknown range */
            default:
                printf("Command Unknown. Type '0' for help.\n");
                break;
        }
    }

    return 0;
}
