#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define UUID_LENGTH 37

struct node {
    char *name;
    char *uuid;
    float price;
    int stock;
    struct node *next;
};

struct item {
    char *name;
    char *uuid;
    float price;
    int stock;
};

typedef struct node *linked;

void display_nodes(linked *head) {
    struct node *current = *head;
    while (current != NULL) {
        printf("---------------------\n");
        printf("Name: %s\n", current->name);
        printf("UUID: %s\n", current->uuid);
        printf("Price: %.2f\n", current->price);
        printf("Stock: %d\n", current->stock);
        current = current->next;
    }
    printf("---------END---------\n");
}

void insert(linked *head, struct item board) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    /* Initializes all variables of the node */
    new_node->name = malloc((strlen(board.name) + 1));
    new_node->uuid = malloc(UUID_LENGTH);
    strcpy(new_node->name, board.name);
    strcpy(new_node->uuid, board.uuid);
    new_node->price = board.price;
    new_node->stock = board.stock;
    
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
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
        new_node->name = malloc((strlen(board.name) + 1));
        new_node->uuid = malloc(UUID_LENGTH);
        strcpy(new_node->name, board.name);
        strcpy(new_node->uuid, board.uuid);
        new_node->price = board.price;
        new_node->stock = board.stock;
        new_node->next = NULL;
    }
    else {
        *head = new_node;
        (*head)->name = (char *)malloc((strlen(board.name) + 1));
        (*head)->uuid = (char *)malloc(UUID_LENGTH);
        strcpy((*head)->name, board.name);
        strcpy((*head)->uuid, board.uuid);
        (*head)->price = board.price;
        (*head)->stock = board.stock;
        (*head)->next = NULL;
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
        free(current->uuid);
        free(current);
        return 0;
    }
    for(i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current->name);
    free(current->uuid);
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
    new_node->name = (char *)malloc((strlen(board.name) + 1));
    new_node->uuid = (char *)malloc(UUID_LENGTH);
    strcpy(new_node->name, board.name);
    strcpy(new_node->uuid, board.uuid);
    new_node->price = board.price;
    new_node->stock = board.stock;
    new_node->next = NULL;
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
        free(current->uuid);
        free(current);
    }
    else {
        free((*head)->name);
        free((*head)->uuid);
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

/* 
 * 32 Bits are for the hexadecimal values.
 * 4 Are for the dashes '-'
 * 1 is for the null terminator character '\0'
 */
 
int genuuid(char *uuid) {
    time_t timestamp = time(NULL);

    /* Calculates the time between actual timestamp and 1582/01/01 in 100ns ticks */
    uint64_t uuid_time = (uint64_t)timestamp * 10000000 + 0x01b21dd213814000L;

    /* XOR the bits for more randomness */
    uuid_time ^= getpid();

    /* Takes the first 32 bits of uuid_time */
    uint32_t time_low = (uuid_time & 0xFFFFFFFF);

    /* The next 16 bits */
    uint16_t time_mid = ((uuid_time >> 32) & 0xFFFF);

    /* The last 12 bits. The final 4 bits are for versioning */
    uint16_t time_hi_and_version = (((uuid_time >> 48) & 0x0FFF) | 0x1000);

    /* Used rand() for getting clock but it can fail to give unique identifiers in the same time */
    uint8_t clock_seq_and_reserved ;
    uint8_t clock_seq_low;

    /* 
    Using CSPRNG (Cryptographic Secure Pseudo-Random Number Generation).
    Opening a file called urandom and reading in binary mode "rb".
    Reads 1 byte once from urandom.
    */
    FILE *urandom = fopen("/dev/urandom", "rb");
    fread(&clock_seq_and_reserved, 1, 1, urandom);
    fread(&clock_seq_low, 1, 1, urandom);
    fclose(urandom); 

    clock_seq_and_reserved = (clock_seq_and_reserved & 0x0F) | 0x10;
    
    /* A hardcoded IEEE MAC Address */
    uint8_t mac[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    sprintf(uuid, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
            time_low,
            time_mid,
            time_hi_and_version,
            clock_seq_and_reserved,
            clock_seq_low,
            mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]
    );
    return 0;
}
