#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    // Step 1: Create adjacency list
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphSize = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int));
    }
    
    // Step 2: Create indegree array
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        
        graph[b][graphSize[b]++] = a;  // b → a
        indegree[a]++;
    }
    
    // Step 3: Queue for BFS
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    // Step 4: Result array
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    
    while (front < rear) {
        int curr = queue[front++];
        result[count++] = curr;
        
        for (int i = 0; i < graphSize[curr]; i++) {
            int neighbor = graph[curr][i];
            indegree[neighbor]--;
            
            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }
    
    // Step 5: Check if valid
    if (count == numCourses) {
        *returnSize = numCourses;
        return result;
    }
    
    *returnSize = 0;
    return (int*)malloc(0);  // return empty array
}
