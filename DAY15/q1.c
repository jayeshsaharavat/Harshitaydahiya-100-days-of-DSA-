#include <stdio.h>

#define MAX_SIZE 200

int main() {
    int m, n;
    int matrix[MAX_SIZE][MAX_SIZE];
    long long sum = 0;
  
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
    
    printf("%lld\n", sum);
    
    return 0;
}
