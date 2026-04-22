#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));    
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
int dequeue() {
    if (front == NULL) {
        return -1;
    }
    struct Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return value;
}
int main() {
    int N;
    scanf("%d", &N);
    char operation[10];
    int value;
    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        if (operation[0] == 'e') { 
            scanf("%d", &value);
            enqueue(value);
        } else if (operation[0] == 'd') {  
            int result = dequeue();
            printf("%d\n", result);
        }
    }
    return 0;
}