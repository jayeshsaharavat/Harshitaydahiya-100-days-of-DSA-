#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100000];  
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max_val = arr[0];
    int min_val = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
        if(arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    
    printf("Max: %d\n", max_val);
    printf("Min: %d\n", min_val);
    
    return 0;
}
