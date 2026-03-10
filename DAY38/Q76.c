//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
//You can only see the k numbers in the window. Each time the sliding window moves right by one position.



#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int *deque = (int*)malloc(numsSize * sizeof(int)); // store indices

    int front = 0, rear = -1;
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++) {

        // Remove indices out of current window
        if (front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements from back
        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        // Insert current index
        deque[++rear] = i;

        // Window formed
        if (i >= k - 1)
            result[i - k + 1] = nums[deque[front]];
    }

    free(deque);
    return result;
}
