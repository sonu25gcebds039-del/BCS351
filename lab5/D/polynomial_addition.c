#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insert(struct Node **poly, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
    struct Node *temp;
    if (*poly == NULL) {
        *poly = newNode;
    }
    else {
        temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(struct Node *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}
struct Node* addPolynomial(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insert(&result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;
    int n, i;
    int coeff, exp;
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(&poly1, coeff, exp);
    }
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert(&poly2, coeff, exp);
    }
    printf("\nFirst Polynomial  : ");
    display(poly1);
    printf("Second Polynomial : ");
    display(poly2);
    sum = addPolynomial(poly1, poly2);
    printf("Sum               : ");
    display(sum);
    return 0;
}