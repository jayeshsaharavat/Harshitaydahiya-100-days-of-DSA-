#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** graph, int* graphColSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, graphColSize, visited, recStack))
                return true;
        } 
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Step 1: Create adjacency list
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // Fill graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphColSize[b]++] = a; // b → a
    }

    // Step 2: visited + recursion stack
    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    // Step 3: DFS on all nodes
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, graphColSize, visited, recStack))
                return false; // cycle exists
        }
    }

    return true; // no cycle
}
