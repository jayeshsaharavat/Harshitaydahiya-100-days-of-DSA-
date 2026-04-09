//Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX], front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

void topologicalSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int topo[MAX], index = 0;

    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    // Step 3: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        topo[index++] = node;

        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Step 4: Check cycle
    if (index != V) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int V = 6;

    // Adjacency matrix
    int adj[MAX][MAX] = {0};

    // Example graph
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V, adj);

    return 0;
}
