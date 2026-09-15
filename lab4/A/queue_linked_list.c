#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into queue\n", value);
}

void dequeue() 
{
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("%d deleted from queue\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void display() 
{
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
