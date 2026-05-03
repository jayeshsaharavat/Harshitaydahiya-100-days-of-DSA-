#include <stdlib.h>

// Swap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    int target = numsSize - k;

    while (left <= right) {
        // Random pivot
        int pivot = nums[left + rand() % (right - left + 1)];

        // 3-way partition
        int low = left, mid = left, high = right;

        while (mid <= high) {
            if (nums[mid] < pivot) {
                swap(&nums[low], &nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] > pivot) {
                swap(&nums[mid], &nums[high]);
                high--;
            }
            else {
                mid++;
            }
        }

        // Now:
        // [left ... low-1] < pivot
        // [low ... high] == pivot
        // [high+1 ... right] > pivot

        if (target >= low && target <= high)
            return nums[target];
        else if (target < low)
            right = low - 1;
        else
            left = high + 1;
    }

    return -1;
}
