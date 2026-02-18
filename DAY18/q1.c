#include <stdio.h>

int main() {
    int n, k;
    int arr[100];

    // Read size
    scanf("%d", &n);

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read rotation count
    scanf("%d", &k);

    // Handle large k
    k = k % n;

    // Print rotated array
    for(int i = n - k; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < n - k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
