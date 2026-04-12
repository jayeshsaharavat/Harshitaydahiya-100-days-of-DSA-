#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate Manhattan Distance
int manhattan(int *a, int *b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;

    int *minDist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));

    // Initialize distances
    for(int i = 0; i < n; i++)
        minDist[i] = INT_MAX;

    minDist[0] = 0;  // start from point 0
    int totalCost = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;

        // Pick minimum distance node not visited
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                int dist = manhattan(points[u], points[v]);
                if(dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);

    return totalCost;
}
