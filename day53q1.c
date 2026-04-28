#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct QNode {
    struct Node* node;
    int hd;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
void verticalOrder(struct Node* root) {
    if (root == NULL) return;
    struct QNode queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct QNode){root, 0};
    int map[2000][100];  // HD range [-1000,1000]
    int count[2000] = {0};
    int min_hd = 0, max_hd = 0;
    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd + 1000; // shift index
        map[hd][count[hd]++] = curr->data;
        if (temp.hd < min_hd) min_hd = temp.hd;
        if (temp.hd > max_hd) max_hd = temp.hd;
        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, temp.hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, temp.hd + 1};
    }
    for (int i = min_hd; i <= max_hd; i++) {
        int idx = i + 1000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}