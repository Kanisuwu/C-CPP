#include <stdio.h>
#include <stdlib.h>

/*
 * Inorder = Left, Root, Right
 * Preorder = Root, left, right
 * Postorder = left, right, root
 */ 
struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

void insert(struct tree **treePtr, int value) {
    if (*treePtr == NULL) { /* tree is empty */
        *treePtr = (struct tree *)malloc(sizeof(struct tree));
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->left = NULL;
            (*treePtr)->right = NULL;
        }
        else {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else { /* tree is not empty */

        /* data to insert is less than data in current node */
        if (value < (*treePtr)->data) {
            insert(&((*treePtr)->left), value);
        }
        /* data to insert is greater than data in current node */
        else if (value > (*treePtr)->data) {
            insert(&((*treePtr)->right), value);
        }
        /* DUPLICATE VALUE */
        else {
            printf("dup\n");
        }
    }
}

void inOrder(struct tree **treePtr) {
    if (*treePtr != NULL) {
        inOrder(&((*treePtr)->left));
        printf("%3d", (*treePtr)->data);
        inOrder(&((*treePtr)->right));
    }
}

void preOrder(struct tree **treePtr) {
    if (*treePtr != NULL) {
        printf("%3d", (*treePtr)->data);
        preOrder(&((*treePtr)->left));
        preOrder(&((*treePtr)->right));
    }
}

void postOrder(struct tree **treePtr) {
    if (*treePtr != NULL) {
        postOrder(&((*treePtr)->left));
        postOrder(&((*treePtr)->right));
        printf("%3d", (*treePtr)->data);
    }
}

int main(int argc, char* argv[]) {
    return 0;
}
