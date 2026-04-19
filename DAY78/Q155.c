#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST(int graph[MAX][MAX], int n) {
    int key[MAX];       // Minimum weight to include node
    int visited[MAX];   // Track visited nodes

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // Start from node 1
    int total_weight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;
        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return total_weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // Undirected graph
    }

    int result = primMST(graph, n);
    printf("%d\n", result);

    return 0;
}
