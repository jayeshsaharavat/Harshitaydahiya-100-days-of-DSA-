#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Adjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
