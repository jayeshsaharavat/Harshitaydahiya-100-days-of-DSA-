#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int found;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -231) continue;
        
        found = 0;
        printf("%d:", arr[i]);
        
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                found++;
                arr[j] = -231; 
              
        }
        printf("%d", found);
        
        if (i < n - 1) printf(" ");
    }
    
    printf("\n");
    free(arr);
    return 0;
}
