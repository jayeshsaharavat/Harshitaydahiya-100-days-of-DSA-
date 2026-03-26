//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue structure
struct Queue {
    struct TreeNode* arr[1000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Zigzag Traversal
void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        int level[size];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);

            level[i] = node->val;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        // Print level in required order
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight; // toggle direction
    }
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
