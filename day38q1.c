#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int deque[MAX];
int front = -1, rear = -1;
int empty() {
    return (front == -1);
}
int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}
void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
}
void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}
int pop_front() {
    if (empty()) return -1;
    int val = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    return val;
}
int pop_back() {
    if (empty()) return -1;
    int val = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    return val;
}
int get_front() {
    if (empty()) return -1;
    return deque[front];
}
int get_back() {
    if (empty()) return -1;
    return deque[rear];
}
void clear() {
    front = rear = -1;
}
void reverse() {
    if (empty()) return;
    int i = front, j = rear;
    int temp;
    while (i != j && (i + MAX - 1) % MAX != j) {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}
void sort() {
    int n = size();
    if (n <= 1) return;
    int arr[n];
    int i = front;
    for (int j = 0; j < n; j++) {
        arr[j] = deque[i];
        i = (i + 1) % MAX;
    }
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (arr[b] > arr[b + 1]) {
                int t = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = t;
            }
        }
    }
    i = front;
    for (int j = 0; j < n; j++) {
        deque[i] = arr[j];
        i = (i + 1) % MAX;
    }
}
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, x;
    while (1) {
        printf("\n1.push_front 2.push_back 3.pop_front 4.pop_back\n");
        printf("5.front 6.back 7.size 8.empty\n");
        printf("9.clear 10.reverse 11.sort 12.display 13.exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &x);
                push_front(x);
                break;
            case 2:
                scanf("%d", &x);
                push_back(x);
                break;
            case 3:
                printf("%d\n", pop_front());
                break;
            case 4:
                printf("%d\n", pop_back());
                break;
            case 5:
                printf("%d\n", get_front());
                break;
            case 6:
                printf("%d\n", get_back());
                break;
            case 7:
                printf("%d\n", size());
                break;
            case 8:
                printf("%d\n", empty());
                break;
            case 9:
                clear();
                break;
            case 10:
                reverse();
                break;
            case 11:
                sort();
                break;
            case 12:
                display();
                break;
            case 13:
                exit(0);
        }
    }
    return 0;
}