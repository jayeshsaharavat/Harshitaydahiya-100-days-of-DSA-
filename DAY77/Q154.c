#include <stdlib.h>

int timeCounter;

void dfs(int u, int parent, int** graph, int* graphSize,
         int* disc, int* low, int* visited,
         int** result, int* colSizes, int* idx) {

    visited[u] = 1;
    disc[u] = low[u] = timeCounter++;

    for (int i = 0; i < graphSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u, graph, graphSize, disc, low, visited, result, colSizes, idx);

            if (low[v] < low[u]) low[u] = low[v];

            if (low[v] > disc[u]) {
                result[*idx] = (int*)malloc(2 * sizeof(int));
                result[*idx][0] = u;
                result[*idx][1] = v;
                colSizes[*idx] = 2;
                (*idx)++;
            }
        } else {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize,
                          int** returnColumnSizes) {

    int* degree = (int*)calloc(n, sizeof(int));

    // Step 1: Count degree
    for (int i = 0; i < connectionsSize; i++) {
        degree[connections[i][0]]++;
        degree[connections[i][1]]++;
    }

    // Step 2: Allocate exact memory
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Step 3: Fill graph
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    // Step 4: Tarjan setup
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    int* colSizes = (int*)malloc(connectionsSize * sizeof(int));

    timeCounter = 0;
    int idx = 0;

    dfs(0, -1, graph, graphSize, disc, low, visited, result, colSizes, &idx);

    *returnSize = idx;
    *returnColumnSizes = colSizes;

    return result;
}
