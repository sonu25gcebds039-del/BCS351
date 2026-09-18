#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};
int main() {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } 
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("\nDoubly Linked List (Forward): ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nDoubly Linked List (Backward): ");
    temp = temp;   
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    return 0;
}