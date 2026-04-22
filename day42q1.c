#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
int stack[MAX];
int top = -1;
void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
void push(int value) {
    if (top == MAX - 1) return;
    stack[++top] = value;
}
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}
int main() {
    int N, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    while (front <= rear) {
        push(dequeue());
    }
    front = rear = -1;
    while (top != -1) {
        enqueue(pop());
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}