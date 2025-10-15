#include <stdio.h>
#include <stdlib.h>

// Define structure for the tree node
struct tree {
    int head;
    struct tree *l, *r;
};

// Function declarations
void insert(struct tree **ptr);
void inorder(struct tree *ptr);
void preorder(struct tree *ptr);
void postorder(struct tree *ptr);

int main() {
    struct tree *r = NULL;
    int choice;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        printf("\n===============================");
        printf("\n      Binary Tree Program");
        printf("\n===============================");
        printf("\n 1. Create Tree");
        printf("\n 2. Traverse In-Order");
        printf("\n 3. Traverse Pre-Order");
        printf("\n 4. Traverse Post-Order");
        printf("\n 5. Exit");
        printf("\n===============================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&r);
                break;

            case 2:
                printf("\nIn-Order Traversal (Left, Root, Right): ");
                inorder(r);
                printf("\n");
                break;

            case 3:
                printf("\nPre-Order Traversal (Root, Left, Right): ");
                preorder(r);
                printf("\n");
                break;

            case 4:
                printf("\nPost-Order Traversal (Left, Right, Root): ");
                postorder(r);
                printf("\n");
                break;

            case 5:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &cont);
    }

    return 0;
}

// Function to insert nodes
void insert(struct tree **ptr) {
    int n, in;
    if (*ptr == NULL) {
        *ptr = (struct tree *)malloc(sizeof(struct tree));
        if (*ptr == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("\nEnter the element: ");
        scanf("%d", &n);
        (*ptr)->head = n;
        (*ptr)->l = NULL;
        (*ptr)->r = NULL;
        return;
    }

    printf("\n1. Left Element");
    printf("\n2. Right Element");
    printf("\nEnter your choice: ");
    scanf("%d", &in);

    switch (in) {
        case 1:
            insert(&(*ptr)->l);
            break;
        case 2:
            insert(&(*ptr)->r);
            break;
        default:
            printf("\nInvalid choice!");
    }
}

// Inorder Traversal
void inorder(struct tree *ptr) {
    if (ptr != NULL) {
        inorder(ptr->l);
        printf("%d ", ptr->head);
        inorder(ptr->r);
    }
}

// Preorder Traversal
void preorder(struct tree *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->head);
        preorder(ptr->l);
        preorder(ptr->r);
    }
}

// Postorder Traversal
void postorder(struct tree *ptr) {
    if (ptr != NULL) {
        postorder(ptr->l);
        postorder(ptr->r);
        printf("%d ", ptr->head);
    }
}
