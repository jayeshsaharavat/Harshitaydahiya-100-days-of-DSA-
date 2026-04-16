bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];

    // Initialize all nodes as uncolored (-1)
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Check for all components (graph may be disconnected)
    for (int i = 0; i < graphSize; i++) {
        if (color[i] != -1) continue;

        // BFS queue
        int queue[graphSize];
        int front = 0, rear = 0;

        queue[rear++] = i;
        color[i] = 0;  // Start coloring with 0

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < graphColSize[node]; j++) {
                int neighbor = graph[node][j];

                // If not colored, assign opposite color
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                // If same color → not bipartite
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}
