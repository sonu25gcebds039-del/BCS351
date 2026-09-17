#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *rear = NULL;
void enqueue(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    if (rear == NULL) {
        rear = newNode;
        newNode->next = rear;
    }
    else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into queue.\n", value);
}
void dequeue() {
    struct Node *front;
    if (rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    front = rear->next;
    if (front == rear) {
        rear = NULL;
    }
    else {
        rear->next = front->next;
    }
    printf("%d deleted from queue.\n", front->data);
    free(front);
}
void display() {
    struct Node *temp;
    if (rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    temp = rear->next;   // front
    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
