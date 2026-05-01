#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + arr[i] <= maxTime) {
            currentTime += arr[i];
        } else {
            painters++;
            currentTime = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int low = 0, high = 0, ans = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1; // increase time
        }
    }

    return ans;
}

int main() {
    int n = 4, k = 2;
    int arr[] = {10, 20, 30, 40};

    printf("Minimum time: %d\n", minTime(arr, n, k));

    return 0;
}
