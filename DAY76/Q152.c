#include <stdio.h>
#include <stdlib.h>

#define MAX 101

// Map original node value to cloned node
struct Node* visited[MAX];

// Function to create a new node
struct Node* createNode(int val, int size) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = size;
    node->neighbors = (struct Node**)malloc(size * sizeof(struct Node*));
    return node;
}

// DFS function to clone graph
struct Node* dfs(struct Node* node) {
    if (node == NULL) return NULL;

    // If already cloned
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create clone
    struct Node* clone = createNode(node->val, node->numNeighbors);
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

// Main function required by LeetCode
struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) return NULL;

    // Initialize visited array
    for (int i = 0; i < MAX; i++) {
        visited[i] = NULL;
    }

    return dfs(s);
}
