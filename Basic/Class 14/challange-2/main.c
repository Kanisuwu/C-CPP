#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char *pItemName;
    int quantity;
    float price;
    float amount;
};

void writeItem(struct item *pItem) {
    char tempString[50];
    printf("Enter product name: ");
    scanf("%s", tempString);

    size_t nameLength = strlen(tempString);

    while ((nameLength + 1) < 3) {
        printf("Invalid name. Try again: ");
        scanf("%s", tempString);
        nameLength = strlen(tempString);
    }

    pItem->pItemName = (char*)malloc((nameLength+1) * sizeof(char));
    strcpy(pItem->pItemName, tempString);
    
    printf("Enter quantity: ");
    scanf("%i", &pItem->quantity);
    printf("Enter price: ");
    scanf("%f", &pItem->price);
    pItem->amount = pItem->quantity * pItem->price;
}

void printItem(struct item *pItem) {
    printf("\n---------- ITEM CHARACTERISTIC ----------\n");
    printf("\n");
    printf("Name: %s\n", pItem->pItemName);
    printf("Quantity: %i\n", pItem->quantity);
    printf("Price: %.2f\n", pItem->price);
    printf("Amount: %.2f\n", pItem->amount);
}

int main(void) {

    struct item *Item;

    Item = (struct item*)malloc(sizeof(struct item));

    writeItem(Item);

    printItem(Item);

    free(Item->pItemName);
    free(Item);

    return 0;
}
