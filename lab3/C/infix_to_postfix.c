#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop();
            }
        }
        else {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    int choice;
    char infix[MAX];
    do {
        printf("\n----- MENU -----\n");
        printf("1. Infix to Postfix\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                top = -1;  
                infixToPostfix(infix);
                break;

            case 2:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 2);

    return 0;
}

