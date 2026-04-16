#include <stdio.h>

// Function to find maximum length of zero sum subarray
int longestZeroSumSubarray(int arr[], int n) {
    int prefix_sum = 0;
    int max_len = 0;

    // Hashmap using array (assuming sum range is limited)
    // Adjust size if needed
    int hash[1000];
    
    // Initialize all values to -1
    for (int i = 0; i < 1000; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum = 0 from start
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        // Shift index for negative sums
        int index = prefix_sum + 500;

        if (hash[index] != -1) {
            int length = i - hash[index];
            if (length > max_len) {
                max_len = length;
            }
        } else {
            hash[index] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("Length of longest zero sum subarray: %d\n", result);

    return 0;
}
