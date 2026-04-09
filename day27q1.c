#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}
int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff;
    struct Node *ptr1 = head1, *ptr2 = head2;
    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    while (ptr1 && ptr2) {
        if (ptr1->data == ptr2->data) {
            return ptr1->data;  // Intersection found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1; 
}
int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = createList(n);
    scanf("%d", &m);
    struct Node* head2 = createList(m);
    int result = findIntersection(head1, head2);
    if (result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");
    return 0;
}