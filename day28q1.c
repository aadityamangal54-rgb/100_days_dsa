#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, i, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("List is empty\n");
        return 0;
    }
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // point to itself initially
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head; // maintain circular link
            temp = newNode;
        }
    }
    printf("Circular Linked List: ");
    temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head); 
    }
    return 0;
}