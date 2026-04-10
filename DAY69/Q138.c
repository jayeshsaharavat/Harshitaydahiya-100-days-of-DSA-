#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 6005

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[105];

// Min Heap Node
struct HeapNode {
    int v, dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode arr[MAX];
};

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

// Push
void push(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = dist;

    while (i && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Pop
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify(h, 0);
    return root;
}

// Main function required by LeetCode
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    
    // Initialize graph
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    // Build graph
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->v = v;
        newNode->w = w;
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int dist[105];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[k] = 0;
    push(&heap, k, 0);

    while (heap.size > 0) {
        struct HeapNode cur = pop(&heap);
        int u = cur.v;

        struct Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}
