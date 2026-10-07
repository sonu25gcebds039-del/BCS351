#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
struct Node* createNode(int data) 
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
struct Node* insert(struct Node* root, int data) 
{ 
    if (root == NULL) { 
        return createNode(data); 
    } 
    if (data < root->data) 
    { 
        root->left = insert(root->left, data); 
    } 
    else if (data > root->data) { 
    root->right = insert(root->right, data); 
    } 
    return root; 
} 
void inorderTraversal(struct Node* root) { 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("%d ", root->data); 
        inorderTraversal(root->right); 
    } 
} 
int main() { 
    struct Node* root = NULL; 
    int choice, data; 
    while (1) { 
        printf("Binary Search Tree Menu:\n"); 
        printf("1. Insert a node\n"); 
        printf("2. Print in-order traversal\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert: "); 
                scanf("%d", &data); 
                root = insert(root, data); 
                break; 
            case 2: 
                printf("In-order traversal: "); 
                inorderTraversal(root); 
                printf("\n"); 
                break; 
            case 3: 
                exit(0); 
            default: 
            printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
}