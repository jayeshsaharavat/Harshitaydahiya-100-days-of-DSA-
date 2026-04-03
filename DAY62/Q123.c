// Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add edge (undirected graph)
void addEdge(struct Node* adj[], int u, int v) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Add u to v's list
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Function to print adjacency list
void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        printf("Vertex %d: ", i);

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Create array of adjacency lists
    struct Node* adj[n];

    // Initialize all lists as empty
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("\nAdjacency List Representation:\n");
    printGraph(adj, n);

    return 0;
}
